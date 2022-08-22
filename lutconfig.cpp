#include "lutconfig.h"
#include "ui_lutconfig.h"

LUTConfig::LUTConfig(QWidget* parent) :
		SettingsWidget(parent),
		ui(new Ui::LUTConfig)
{
	ui->setupUi(this);
}

LUTConfig::~LUTConfig()
{
	delete ui;
}

void LUTConfig::update_game_settings()
{

}

void LUTConfig::set_settings(Game* game)
{
	ui->enable_lut_checkbox->setChecked(game->lut_enabled);
	ui->select_lut_file_button->setText(game->lut_file_path);
}
