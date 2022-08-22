//
// Created by jorge on 8/21/22.
//

#ifndef VKBASALT_GUI_STEAMGAMESMANAGER_H
#define VKBASALT_GUI_STEAMGAMESMANAGER_H


#include <QDir>
#include "game.h"
#include "gamesmanager.h"


class SteamGamesManager : public GamesManager
{
	public:
		explicit SteamGamesManager(const QDir& dir);

		virtual ~SteamGamesManager();

		void refresh() final;

	private:
		const QString steam_library_path;
		static const QString STEAM_CUSTOM_LIBRARY_PATH;
		QFile games_list_path;

		// Parsing steam files
		static const QString STEAM_APP_ID_HEADER;
		static const QString STEAM_NAME_HEADER;
		static const int STEAM_VALID_LINE_COMPONENTS;

		QString get_game_title(const Game* game) override;

		Game* extract_game_data(QFile& file);
};


#endif //VKBASALT_GUI_STEAMGAMESMANAGER_H
