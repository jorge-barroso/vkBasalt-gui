#include "gamesdropdownwidget.h"
#include "ui_gamesdropdownwidget.h"

GamesDropdownWidget::GamesDropdownWidget(QWidget *parent) :
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
	ui->games_dropdown_2->addItems(titles);
}
