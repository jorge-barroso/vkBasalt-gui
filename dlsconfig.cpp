#include "dlsconfig.h"
#include "ui_dlsconfig.h"

DLSConfig::DLSConfig(QWidget* parent) :
		SettingsWidget(parent),
		ui(new Ui::DLSConfig)
{
	ui->setupUi(this);
}

DLSConfig::~DLSConfig()
{
	delete ui;
}

void DLSConfig::update_game_settings()
{

}

void DLSConfig::set_settings(Game* game)
{
	ui->enable_dls_checkbox->setEnabled(game->dls_enabled);
	ui->sharpness_slider->setSliderPosition(static_cast<int>(game->dls_sharpness)*10);
	ui->denoise_slider->setSliderPosition(static_cast<int>(game->dls_denoise)*10);
}
