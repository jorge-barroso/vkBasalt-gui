#ifndef CASCONFIG_H
#define CASCONFIG_H

#include <QWidget>
#include "settingswidget.h"

namespace Ui {
class CASConfig;
}

class CASConfig : public SettingsWidget
{
    Q_OBJECT

public:
    explicit CASConfig(QWidget *parent = nullptr);

		void update_game_settings() override;

		void set_settings(Game* game) override;

		~CASConfig();

private:
    Ui::CASConfig *ui;
};

#endif // CASCONFIG_H
