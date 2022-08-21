#ifndef LUTCONFIG_H
#define LUTCONFIG_H

#include <QWidget>

namespace Ui {
class LUTConfig;
}

class LUTConfig : public QWidget
{
    Q_OBJECT

public:
    explicit LUTConfig(QWidget *parent = nullptr);
    ~LUTConfig();

private:
    Ui::LUTConfig *ui;
};

#endif // LUTCONFIG_H
