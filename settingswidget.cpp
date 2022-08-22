//
// Created by jorge on 8/22/22.
//

#include "settingswidget.h"

SettingsWidget::SettingsWidget(QWidget* widget)
		: QWidget(widget)
		, game{ }
{

}

SettingsWidget::~SettingsWidget()
{
	delete game;
}
