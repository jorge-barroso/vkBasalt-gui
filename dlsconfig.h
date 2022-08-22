#ifndef DLSCONFIG_H
#define DLSCONFIG_H

#include <QWidget>
#include "settingswidget.h"

namespace Ui {
class DLSConfig;
}

class DLSConfig : public SettingsWidget
{
    Q_OBJECT

public:
    explicit DLSConfig(QWidget *parent = nullptr);
    ~DLSConfig();

		void update_game_settings() override;

		void set_settings(Game* game) override;

	private:
    Ui::DLSConfig *ui;
};

#endif // DLSCONFIG_H
