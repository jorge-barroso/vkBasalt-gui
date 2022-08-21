#include "dlsconfig.h"
#include "ui_dlsconfig.h"

DLSConfig::DLSConfig(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DLSConfig)
{
    ui->setupUi(this);
}

DLSConfig::~DLSConfig()
{
    delete ui;
}
