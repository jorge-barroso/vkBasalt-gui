#ifndef SMAACONFIG_H
#define SMAACONFIG_H

#include <QWidget>

namespace Ui {
class SMAAConfig;
}

class SMAAConfig : public QWidget
{
    Q_OBJECT

public:
    explicit SMAAConfig(QWidget *parent = nullptr);
    ~SMAAConfig();

private:
    Ui::SMAAConfig *ui;
};

#endif // SMAACONFIG_H
