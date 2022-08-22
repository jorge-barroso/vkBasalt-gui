//
// Created by jorge on 8/22/22.
//
#include <QApplication>
#include <QMessageBox>
#include "gamesmanager.h"

const QString GamesManager::GAMES_LIST_FILE{ "games_list.txt" };

GamesManager::GamesManager(const QDir& dir)
		: games_list_path{ dir.absolutePath() + "/" + GamesManager::GAMES_LIST_FILE }
{

}

void GamesManager::load_list()
{
	if (!games_list_path.open(QIODevice::ReadOnly))
		QMessageBox::warning(nullptr, QApplication::translate("Steam Games", "Could not load games"),
							 games_list_path.errorString());


	QTextStream stream(&games_list_path);
	while (!stream.atEnd())
	{
		Game* game = new Game{ };
		stream >> game;
		games.emplace_back(game);
	}

	games_list_path.close();
}

QStringList GamesManager::get_game_titles()
{
	QStringList game_titles;
	std::transform(games.begin(), games.end(), std::back_inserter(game_titles), [this](auto && PH1) { return get_game_title(std::forward<decltype(PH1)>(PH1)); });
	return game_titles;
}

Game* GamesManager::get_game_configs(int i)
{
	if(i > games.size())
	{
		return nullptr;
	}

	return games[i];
}
