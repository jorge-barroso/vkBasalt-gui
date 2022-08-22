#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>
#include <map>
#include "steamgamesmanager.h"

using GamesReferences = std::vector<std::pair<GamesManager*, int>>;

QT_BEGIN_NAMESPACE
namespace Ui
{
	class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

	public:
		MainWindow(const QDir& config_dir, QWidget* parent = nullptr);

		~MainWindow();

	private slots:

		void refresh_games();

		void change_game_config(int index);

	private:
		Ui::MainWindow* ui;

		QDir config_dir;

		SteamGamesManager steam_games_manager;
		GamesReferences all_games;

		void load_games(bool refresh);

		QStringList load_steam_games(bool refresh);
};

#endif // MAINWINDOW_H
