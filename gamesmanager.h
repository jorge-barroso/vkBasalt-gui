//
// Created by jorge on 8/22/22.
//

#ifndef VKBASALT_GUI_GAMESMANAGER_H
#define VKBASALT_GUI_GAMESMANAGER_H

#include <QDir>
#include "game.h"

class GamesManager
{
	public:
		explicit GamesManager(const QDir& dir);

		virtual void refresh() = 0;

		QStringList get_game_titles();

		Game* get_game_configs(int i);

	protected:
		const QString library_path;

		QFile games_list_path;

		static const QString GAMES_LIST_FILE;

		std::vector<Game*> games;

		void load_list();

		virtual QString get_game_title(const Game* game) = 0;
};

#endif //VKBASALT_GUI_GAMESMANAGER_H
