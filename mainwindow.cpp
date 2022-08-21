#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(const QDir& config_dir, QWidget* parent)
		: QMainWindow(parent)
		, ui(new Ui::MainWindow)
		, config_dir{ config_dir }
		, steam_games_manager(config_dir)
{
	ui->setupUi(this);

	this->load_steam_games();
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::load_steam_games()
{
	const QStringList steam_games{ steam_games_manager.get_game_titles() };
	ui->games_dropdown->add_games(steam_games);
//	std::transform(steam_games.begin(), steam_games.end(), ui->games_dropdown)
}

