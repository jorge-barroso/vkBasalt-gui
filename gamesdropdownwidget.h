#ifndef GAMESDROPDOWNWIDGET_H
#define GAMESDROPDOWNWIDGET_H

#include <QWidget>

namespace Ui
{
	class GamesDropdownWidget;
}

class GamesDropdownWidget : public QWidget
{
	Q_OBJECT

	public:
		explicit GamesDropdownWidget(QWidget* parent = nullptr);

		~GamesDropdownWidget();

		void add_games(const QStringList& titles);

	private:
		Ui::GamesDropdownWidget* ui;
};

#endif // GAMESDROPDOWNWIDGET_H
