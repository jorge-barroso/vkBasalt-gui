#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QDir>
#include <QStandardPaths>

QDir get_config_directory(const QString&);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "vkBasalt-gui_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

	const QString conf_dir_name{ "vkBasalt_gui" };
	const QDir config_dir = get_config_directory(conf_dir_name);

    MainWindow w(config_dir);
    w.show();
    return a.exec();
}


QDir get_config_directory(const QString& conf_dir_name)
{
	const QString user_conf_dir_path{ QStandardPaths::writableLocation(QStandardPaths::ConfigLocation) };
	const QDir user_conf_dir{ QDir(user_conf_dir_path) };
	if (!user_conf_dir.exists(conf_dir_name))
	{
		user_conf_dir.mkdir(conf_dir_name);
	}

	return { user_conf_dir.absolutePath() + "/" + conf_dir_name };
}