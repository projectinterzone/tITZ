#include "community.h"
#include "ui_community.h"

Community::Community(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Community)
{
    ui->setupUi(this);
}

Community::~Community()
{
    delete ui;
}
