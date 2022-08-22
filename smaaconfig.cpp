#include "smaaconfig.h"
#include "ui_smaaconfig.h"

SMAAConfig::SMAAConfig(QWidget* parent) :
		SettingsWidget(parent),
		ui(new Ui::SMAAConfig)
{
	ui->setupUi(this);
}

SMAAConfig::~SMAAConfig()
{
	delete ui;
}

void SMAAConfig::update_game_settings()
{

}

void SMAAConfig::set_settings(Game* game)
{
	ui->enable_smaa_checkbox->setEnabled(game->smaa_enabled);
	ui->threshold_slider->setSliderPosition(static_cast<int>(game->smaa_threshold)*10);
	ui->max_search_steps_slider->setSliderPosition(static_cast<int>(game->smaa_max_search_steps) * 10);
	ui->max_search_steps_diagonal_slider->setSliderPosition(static_cast<int>(game->smaa_max_search_steps_diagonal) * 10);
	ui->corner_rounding_slider->setSliderPosition(static_cast<int>(game->smaa_corner_rounding)*10);

	int edge_detection_method_index{ ui->edge_detection_mode_combobox->findText(game->smaa_edge_detection_method) };
	ui->edge_detection_mode_combobox->setCurrentIndex(edge_detection_method_index);
}
