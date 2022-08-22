//
// Created by jorge on 8/21/22.
//

#include "reshadefilters.h"

ReshadeFilters::ReshadeFilters()
	: SettingsWidget()
	, ui(new Ui::ReshadeFilters)
{
	ui->setupUi(this);
}

ReshadeFilters::~ReshadeFilters() = default;

void ReshadeFilters::update_game_settings()
{

}

void ReshadeFilters::set_settings(Game* game)
{

}
