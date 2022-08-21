#ifndef DLSCONFIG_H
#define DLSCONFIG_H

#include <QWidget>

namespace Ui {
class DLSConfig;
}

class DLSConfig : public QWidget
{
    Q_OBJECT

public:
    explicit DLSConfig(QWidget *parent = nullptr);
    ~DLSConfig();

private:
    Ui::DLSConfig *ui;
};

#endif // DLSCONFIG_H
