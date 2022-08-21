#include "vkbasalteffects.h"
#include "ui_vkbasalteffects.h"

VKBasaltEffects::VKBasaltEffects() :
    QWidget(),
    ui(new Ui::VKBasaltEffects)
{
    ui->setupUi(this);
}

VKBasaltEffects::~VKBasaltEffects()
{
    delete ui;
}
