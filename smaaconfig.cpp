#include "smaaconfig.h"
#include "ui_smaaconfig.h"

SMAAConfig::SMAAConfig(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SMAAConfig)
{
    ui->setupUi(this);
}

SMAAConfig::~SMAAConfig()
{
    delete ui;
}
