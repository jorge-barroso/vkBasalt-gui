#include "bottommenubar.h"
#include "ui_bottommenubar.h"

BottomMenuBar::BottomMenuBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BottomMenuBar)
{
    ui->setupUi(this);
}

BottomMenuBar::~BottomMenuBar()
{
    delete ui;
}
