//
// Created by jorge on 8/21/22.
//

#ifndef VKBASALT_GUI_RESHADEFILTERS_H
#define VKBASALT_GUI_RESHADEFILTERS_H

#include "ui_reshadefilters.h"
#include "settingswidget.h"
#include <QWidget>

namespace Ui
{
	class ReshadeFilters;
}

class ReshadeFilters : public SettingsWidget
{
	Q_OBJECT

	public:
		ReshadeFilters();

		~ReshadeFilters() override;

		void update_game_settings() override;

		void set_settings(Game* game) override;

	private:
		Ui::ReshadeFilters* ui;

};


#endif //VKBASALT_GUI_RESHADEFILTERS_H
