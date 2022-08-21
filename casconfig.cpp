#include "casconfig.h"
#include "ui_casconfig.h"

CASConfig::CASConfig(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CASConfig)
{
    ui->setupUi(this);
}

CASConfig::~CASConfig()
{
    delete ui;
}
