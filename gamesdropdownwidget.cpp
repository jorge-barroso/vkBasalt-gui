#include "gamesdropdownwidget.h"
#include "ui_gamesdropdownwidget.h"

const QString GamesDropdownWidget::GLOBAL_VALUE{ "Global (System)" };

GamesDropdownWidget::GamesDropdownWidget(QWidget* parent) :
		QWidget(parent),
		ui(new Ui::GamesDropdownWidget)
{
	ui->setupUi(this);

}

GamesDropdownWidget::~GamesDropdownWidget()
{
	delete ui;
}

void GamesDropdownWidget::add_games(const QStringList& titles)
{
	ui->games_dropdown_2->blockSignals(true);
	ui->games_dropdown_2->clear();
	ui->games_dropdown_2->blockSignals(false);
	ui->games_dropdown_2->addItem(GamesDropdownWidget::GLOBAL_VALUE);
	ui->games_dropdown_2->addItems(titles);
}

void GamesDropdownWidget::on_refresh_button_2_clicked()
{
	emit refresh_games();
}


void GamesDropdownWidget::on_games_dropdown_2_currentIndexChanged(int index)
{
	emit game_chosen(index);
}

