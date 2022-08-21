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

	signals:

		void refresh_games();

	private slots:

		void on_refresh_button_2_clicked();

	private:
		Ui::GamesDropdownWidget* ui;

		static const QString GLOBAL_VALUE;

};

#endif // GAMESDROPDOWNWIDGET_H
