//
// Created by jorge on 8/21/22.
//

#include <QApplication>
#include <QStandardPaths>
#include <QDirIterator>
#include <QJsonDocument>
#include <QJsonObject>
#include <QCoreApplication>
#include <QMessageBox>
#include "steamgamesmanager.h"

const QString SteamGamesManager::GAMES_LIST_FILE{ "games_list.txt" };
const QString SteamGamesManager::STEAM_CUSTOM_LIBRARY_PATH{ "/Steam/steamapps" };
const QString SteamGamesManager::STEAM_APP_ID_HEADER{ "appid" };
const QString SteamGamesManager::STEAM_NAME_HEADER{ "name" };
const int SteamGamesManager::STEAM_VALID_LINE_COMPONENTS{ 2 };

SteamGamesManager::SteamGamesManager(const QDir& dir)
		: games_list_path{ dir.absolutePath() + "/" + SteamGamesManager::GAMES_LIST_FILE }, steam_library_path{
		QStandardPaths::writableLocation(QStandardPaths::GenericDataLocation) + STEAM_CUSTOM_LIBRARY_PATH }
{
	if (!games_list_path.exists())
	{
		refresh();
	}
	else
	{
		load_list();
	}
}

SteamGamesManager::~SteamGamesManager()
{
	games_list_path.open(QIODevice::WriteOnly | QIODevice::Truncate);
	QTextStream stream(&games_list_path);
	for (const Game* game: games)
	{
		stream << game;
	}

	games_list_path.close();
}

void SteamGamesManager::refresh()
{
	// Search Steam Games Library
	QDirIterator it(steam_library_path, QStringList() << "appmanifest_*", QDir::Files, QDirIterator::Subdirectories);

	// For each game
	while (it.hasNext())
	{
		it.next();

		// get game details
		QFile game_file{ it.filePath() };
		if (!game_file.open(QIODevice::ReadOnly | QIODevice::Text))
		{
			continue;
		}

		Game* game{ this->extract_game_data(game_file) };

		game_file.close();

		games.emplace_back(game);
	}
}

void SteamGamesManager::load_list()
{
	if (!games_list_path.open(QIODevice::ReadOnly))
	{
		QMessageBox::warning(nullptr, QApplication::translate("Steam Games", "Could not load games"),
							 games_list_path.errorString());
	}

	QTextStream stream(&games_list_path);
	while (!stream.atEnd())
	{
		Game* game = new Game{ };
		stream >> game;
		games.emplace_back(game);
	}

	games_list_path.close();
}

QStringList SteamGamesManager::get_game_titles()
{
	QStringList game_titles;
	std::transform(games.begin(), games.end(), std::back_inserter(game_titles), SteamGamesManager::get_game_title);
	return game_titles;
}

QString SteamGamesManager::get_game_title(const Game* game)
{
	return game->title + " (Steam)";
}

// custom and quick extractor of the ACF data steam uses to list app names and IDs
Game* SteamGamesManager::extract_game_data(QFile& file)
{
	// Remove header and first bracket lines
	file.readLine();
	file.readLine();

	QString app_name;
	QString app_common_path;
	long long steam_id;
	while (file.canReadLine())
	{
		const QString line{ file.readLine() };
		const QStringList line_components{ line.split(QRegularExpression(R"([\n\t\"]+)"), Qt::SkipEmptyParts) };
		if (line_components.length() < STEAM_VALID_LINE_COMPONENTS)
		{
			continue;
		}
		if (line_components[0] == STEAM_APP_ID_HEADER)
		{
			steam_id = line_components[1].toLongLong();
		}
		else if (line_components[0] == STEAM_NAME_HEADER)
		{
			app_name = line_components[1];
			app_common_path = steam_library_path + "/common/" + app_name;
		}

		if (steam_id > 0 && app_name.length() > 0)
		{
			break;
		}
	}

	return new Game
			{
					app_name,
					app_common_path,
					steam_id,
			};
}
