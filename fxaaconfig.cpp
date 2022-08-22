#include "fxaaconfig.h"
#include "ui_fxaaconfig.h"

FXAAConfig::FXAAConfig(QWidget *parent) :
		SettingsWidget(parent),
    ui(new Ui::FXAAConfig)
{
    ui->setupUi(this);
}

FXAAConfig::~FXAAConfig()
{
    delete ui;
}

void FXAAConfig::update_game_settings()
{

}

void FXAAConfig::set_settings(Game* game)
{
	ui->enable_fxaa_checkbox->setEnabled(game->fxaa_enabled);
	ui->quality_subpixel_slider->setSliderPosition(static_cast<int>(game->fxaa_quality_subpixel)*10);
	ui->quality_edge_threshold_slider->setSliderPosition(static_cast<int>(game->fxaa_edge_threshold)*10);
	ui->quality_edge_threshold_min_slider->setSliderPosition(static_cast<int>(game->fxaa_edge_threshold_min)*10);
}
