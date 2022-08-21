//
// Created by jorge on 8/21/22.
//

#ifndef VKBASALTEFFECTS_H
#define VKBASALTEFFECTS_H

#include "ui_vkbasalteffects.h"
#include <QWidget>

namespace Ui
{
	class VKBasaltEffects;
}

class VKBasaltEffects : public QWidget
{
	Q_OBJECT

	public:
		VKBasaltEffects();

		~VKBasaltEffects() override;

	private slots:
		void on_comboBox_currentIndexChanged(int index);

		void on_pushButton_clicked();

	private:
		Ui::VKBasaltEffects* ui;
};

#endif // VKBASALTEFFECTS_H
