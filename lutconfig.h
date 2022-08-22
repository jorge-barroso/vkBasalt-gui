#ifndef LUTCONFIG_H
#define LUTCONFIG_H

#include <QWidget>
#include "settingswidget.h"

namespace Ui {
class LUTConfig;
}

class LUTConfig : public SettingsWidget
{
    Q_OBJECT

public:
    explicit LUTConfig(QWidget *parent = nullptr);
    ~LUTConfig();

		void update_game_settings() override;

		void set_settings(Game* game) override;

	private:
    Ui::LUTConfig *ui;
};

#endif // LUTCONFIG_H
