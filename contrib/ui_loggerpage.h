/********************************************************************************
** Form generated from reading UI file 'loggerpage.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGGERPAGE_H
#define UI_LOGGERPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoggerPage
{
public:
    QTableWidget *tblLogs;

    void setupUi(QWidget *LoggerPage)
    {
        if (LoggerPage->objectName().isEmpty())
            LoggerPage->setObjectName(QStringLiteral("LoggerPage"));
        LoggerPage->resize(1020, 632);
        tblLogs = new QTableWidget(LoggerPage);
        if (tblLogs->columnCount() < 2)
            tblLogs->setColumnCount(2);
        tblLogs->setObjectName(QStringLiteral("tblLogs"));
        tblLogs->setGeometry(QRect(20, 20, 831, 591));
        tblLogs->setAlternatingRowColors(true);
        tblLogs->setColumnCount(2);

        retranslateUi(LoggerPage);

        QMetaObject::connectSlotsByName(LoggerPage);
    } // setupUi

    void retranslateUi(QWidget *LoggerPage)
    {
        LoggerPage->setWindowTitle(QApplication::translate("LoggerPage", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class LoggerPage: public Ui_LoggerPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGGERPAGE_H
