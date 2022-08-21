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
		SteamGamesManager(const QDir& dir);

		virtual ~SteamGamesManager();

		void refresh();

	private:
		static const QString GAMES_LIST_FILE;
		const QString games_list_path;
		std::vector<Game> games;
};


#endif //VKBASALT_GUI_STEAMGAMESMANAGER_H
