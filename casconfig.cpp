#include "casconfig.h"
#include "ui_casconfig.h"

CASConfig::CASConfig(QWidget* parent)
		: SettingsWidget(parent)
		, ui(new Ui::CASConfig)
{
	ui->setupUi(this);
}

CASConfig::~CASConfig()
{
	delete ui;
}

void CASConfig::update_game_settings()
{

}

void CASConfig::set_settings(Game* game)
{
	ui->enable_cas_checkbox->setChecked(game->cas_enabled);
	ui->cas_strength_slider->setSliderPosition(static_cast<int>(game->cas_strength)*10);
}
