#include "fxaaconfig.h"
#include "ui_fxaaconfig.h"

FXAAConfig::FXAAConfig(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FXAAConfig)
{
    ui->setupUi(this);
}

FXAAConfig::~FXAAConfig()
{
    delete ui;
}
