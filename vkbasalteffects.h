//
// Created by jorge on 8/21/22.
//

#ifndef VKBASALTEFFECTS_H
#define VKBASALTEFFECTS_H

#include "ui_vkbasalteffects.h"
#include "settingswidget.h"
#include <QWidget>

namespace Ui
{
	class VKBasaltEffects;
}

class VKBasaltEffects : public SettingsWidget
{
	Q_OBJECT

	public:
		VKBasaltEffects();

		~VKBasaltEffects() override;

		void update_game_settings() override;

		void set_settings(Game* game) override;

	private:
		Ui::VKBasaltEffects* ui;
};

#endif // VKBASALTEFFECTS_H
