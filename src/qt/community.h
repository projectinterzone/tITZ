#ifndef COMMUNITY_H
#define COMMUNITY_H

#include <QMainWindow>

namespace Ui {
class Community;
}

class Community : public QMainWindow
{
    Q_OBJECT

public:
    explicit Community(QWidget *parent = 0);
    ~Community();

private:
    Ui::Community *ui;
};

#endif // COMMUNITY_H
