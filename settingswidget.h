//
// Created by jorge on 8/22/22.
//

#ifndef VKBASALT_GUI_SETTINGSWIDGET_H
#define VKBASALT_GUI_SETTINGSWIDGET_H


#include <QWidget>
#include "game.h"

class SettingsWidget : public QWidget
{
	Q_OBJECT
	public:
		explicit SettingsWidget(QWidget* widget = nullptr);

		~SettingsWidget() override;

		virtual void update_game_settings() = 0;

		virtual void set_settings(Game* game) = 0;

	protected:
		Game* game;
};


#endif //VKBASALT_GUI_SETTINGSWIDGET_H
