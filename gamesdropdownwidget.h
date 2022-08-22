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

		void game_chosen(const int index);

	private slots:

		void on_refresh_button_2_clicked();

		void on_games_dropdown_2_currentIndexChanged(int index);

	private:
		Ui::GamesDropdownWidget* ui;

		static const QString GLOBAL_VALUE;
};

#endif // GAMESDROPDOWNWIDGET_H
