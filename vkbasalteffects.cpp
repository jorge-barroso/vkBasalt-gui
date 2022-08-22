#include "vkbasalteffects.h"
#include "ui_vkbasalteffects.h"

VKBasaltEffects::VKBasaltEffects() :
    SettingsWidget(),
    ui(new Ui::VKBasaltEffects)
{
    ui->setupUi(this);
}

VKBasaltEffects::~VKBasaltEffects()
{
    delete ui;
}

void VKBasaltEffects::update_game_settings()
{

}

void VKBasaltEffects::set_settings(Game* game)
{
	ui->cas_config->set_settings(game);
	ui->dls_config->set_settings(game);
	ui->fxaa_config->set_settings(game);
	ui->smaa_config->set_settings(game);
	ui->lut_config->set_settings(game);
}
