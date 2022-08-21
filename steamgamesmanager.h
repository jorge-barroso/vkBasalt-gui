//
// Created by jorge on 8/21/22.
//

#ifndef VKBASALT_GUI_STEAMGAMESMANAGER_H
#define VKBASALT_GUI_STEAMGAMESMANAGER_H


#include <QDir>
#include "game.h"


class SteamGamesManager
{
	public:
		explicit SteamGamesManager(const QDir& dir);

		virtual ~SteamGamesManager();

		void refresh();

		QStringList get_game_titles();

	private:
		///home/jorge/.local/share/Steam/steamapps/common/
		const QString steam_library_path;
		static const QString STEAM_CUSTOM_LIBRARY_PATH;
		static const QString GAMES_LIST_FILE;
		QFile games_list_path;

		static const QString STEAM_APP_ID_HEADER;
		static const QString STEAM_NAME_HEADER;
		static const int STEAM_VALID_LINE_COMPONENTS;

		std::vector<Game*> games;

		void load_list();

		static QString get_game_title(const Game* game) ;

		Game* extract_game_data(QFile& file);
};


#endif //VKBASALT_GUI_STEAMGAMESMANAGER_H
