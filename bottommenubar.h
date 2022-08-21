#ifndef BOTTOMMENUBAR_H
#define BOTTOMMENUBAR_H

#include <QWidget>

namespace Ui {
class BottomMenuBar;
}

class BottomMenuBar : public QWidget
{
    Q_OBJECT

public:
    explicit BottomMenuBar(QWidget *parent = nullptr);
    ~BottomMenuBar();

private:
    Ui::BottomMenuBar *ui;
};

#endif // BOTTOMMENUBAR_H
