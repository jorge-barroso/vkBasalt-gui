//
// Created by jorge on 8/21/22.
//

#include "reshadefilters.h"

ReshadeFilters::ReshadeFilters()
	: QWidget()
	, ui(new Ui::ReshadeFilters)
{
	ui->setupUi(this);
}

ReshadeFilters::~ReshadeFilters() = default;
