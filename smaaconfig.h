#ifndef SMAACONFIG_H
#define SMAACONFIG_H

#include <QWidget>
#include "settingswidget.h"

namespace Ui {
class SMAAConfig;
}

class SMAAConfig : public SettingsWidget
{
    Q_OBJECT

public:
    explicit SMAAConfig(QWidget *parent = nullptr);
    ~SMAAConfig();

		void update_game_settings() override;

		void set_settings(Game* game) override;

	private:
    Ui::SMAAConfig *ui;
};

#endif // SMAACONFIG_H
