#include <QStringList>
#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(const QDir& config_dir, QWidget* parent)
		: QMainWindow(parent), ui(new Ui::MainWindow), config_dir{ config_dir }, steam_games_manager(config_dir)
{
	ui->setupUi(this);

	this->load_games(false);

	connect(ui->games_dropdown, &GamesDropdownWidget::refresh_games, this, &MainWindow::refresh_games);
	connect(ui->games_dropdown, &GamesDropdownWidget::game_chosen, this, &MainWindow::change_game_config);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::refresh_games()
{
	load_games(true);
}

void MainWindow::load_games(const bool refresh)
{
	QStringList games{ load_steam_games(refresh) };
	GamesManager* steam_manager_ptr{ &steam_games_manager };
	for (int i = 0; i < games.length(); ++i)
	{
		std::pair<GamesManager*, int> entry{ steam_manager_ptr, i };
		all_games.emplace_back(entry);
	}

	ui->games_dropdown->add_games(games);
}

QStringList MainWindow::load_steam_games(const bool refresh)
{
	if (refresh)
	{
		steam_games_manager.refresh();
	}

	return steam_games_manager.get_game_titles();
}

void MainWindow::change_game_config(const int index)
{
	// TODO still need to figure out the global settings
	std::pair<GamesManager*, int> game{ all_games[index - 1] };
	Game* game_configs{ game.first->get_game_configs(game.second) };
	qDebug() << "Changing Game to " << game_configs->title;
	ui->vkbasalt_effects->set_settings(game_configs);
	ui->reshade_filters->set_settings(game_configs);
}

