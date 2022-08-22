#ifndef FXAACONFIG_H
#define FXAACONFIG_H

#include <QWidget>
#include "settingswidget.h"

namespace Ui {
class FXAAConfig;
}

class FXAAConfig : public SettingsWidget
{
    Q_OBJECT

public:
    explicit FXAAConfig(QWidget *parent = nullptr);
    ~FXAAConfig();

		void update_game_settings() override;

		void set_settings(Game* game) override;

	private:
    Ui::FXAAConfig *ui;
};

#endif // FXAACONFIG_H
