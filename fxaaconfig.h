#ifndef FXAACONFIG_H
#define FXAACONFIG_H

#include <QWidget>

namespace Ui {
class FXAAConfig;
}

class FXAAConfig : public QWidget
{
    Q_OBJECT

public:
    explicit FXAAConfig(QWidget *parent = nullptr);
    ~FXAAConfig();

private:
    Ui::FXAAConfig *ui;
};

#endif // FXAACONFIG_H
