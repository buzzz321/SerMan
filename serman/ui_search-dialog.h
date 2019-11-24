/********************************************************************************
** Form generated from reading UI file 'search-dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCH_2D_DIALOG_H
#define UI_SEARCH_2D_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SearchDialogWindow
{
public:
    QPushButton *search;
    QPushButton *exit;
    QLineEdit *lineEdit;

    void setupUi(QDialog *SearchDialogWindow)
    {
        if (SearchDialogWindow->objectName().isEmpty())
            SearchDialogWindow->setObjectName(QStringLiteral("SearchDialogWindow"));
        SearchDialogWindow->resize(403, 134);
        search = new QPushButton(SearchDialogWindow);
        search->setObjectName(QStringLiteral("search"));
        search->setGeometry(QRect(220, 80, 80, 22));
        exit = new QPushButton(SearchDialogWindow);
        exit->setObjectName(QStringLiteral("exit"));
        exit->setGeometry(QRect(310, 80, 80, 22));
        lineEdit = new QLineEdit(SearchDialogWindow);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(9, 51, 381, 22));
        QWidget::setTabOrder(lineEdit, search);
        QWidget::setTabOrder(search, exit);

        retranslateUi(SearchDialogWindow);

        QMetaObject::connectSlotsByName(SearchDialogWindow);
    } // setupUi

    void retranslateUi(QDialog *SearchDialogWindow)
    {
        SearchDialogWindow->setWindowTitle(QApplication::translate("SearchDialogWindow", "Dialog", Q_NULLPTR));
        search->setText(QApplication::translate("SearchDialogWindow", "Search", Q_NULLPTR));
        exit->setText(QApplication::translate("SearchDialogWindow", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SearchDialogWindow: public Ui_SearchDialogWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCH_2D_DIALOG_H
