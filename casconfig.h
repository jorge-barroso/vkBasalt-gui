#ifndef CASCONFIG_H
#define CASCONFIG_H

#include <QWidget>

namespace Ui {
class CASConfig;
}

class CASConfig : public QWidget
{
    Q_OBJECT

public:
    explicit CASConfig(QWidget *parent = nullptr);
    ~CASConfig();

private:
    Ui::CASConfig *ui;
};

#endif // CASCONFIG_H
