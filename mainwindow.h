#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>
#include "steamgamesmanager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(const QDir& config_dir, QWidget* parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

	QDir config_dir;

	SteamGamesManager steam_games_manager;

		void load_steam_games();
};
#endif // MAINWINDOW_H
