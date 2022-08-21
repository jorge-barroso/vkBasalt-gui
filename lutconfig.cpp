#include "lutconfig.h"
#include "ui_lutconfig.h"

LUTConfig::LUTConfig(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LUTConfig)
{
    ui->setupUi(this);
}

LUTConfig::~LUTConfig()
{
    delete ui;
}
