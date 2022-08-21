#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(const QDir& config_dir, QWidget* parent)
		: QMainWindow(parent)
		, ui(new Ui::MainWindow)
		, config_dir{ config_dir }
		, steam_games_manager(config_dir)
{
	ui->setupUi(this);
}

MainWindow::~MainWindow()
{
	delete ui;
}

