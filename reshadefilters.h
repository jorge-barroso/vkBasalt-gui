//
// Created by jorge on 8/21/22.
//

#ifndef VKBASALT_GUI_RESHADEFILTERS_H
#define VKBASALT_GUI_RESHADEFILTERS_H

#include "ui_reshadefilters.h"
#include <QWidget>

namespace Ui
{
	class ReshadeFilters;
}

class ReshadeFilters : public QWidget
{
	Q_OBJECT

	public:
		ReshadeFilters();

		~ReshadeFilters() override;

	private:
		Ui::ReshadeFilters* ui;

};


#endif //VKBASALT_GUI_RESHADEFILTERS_H
