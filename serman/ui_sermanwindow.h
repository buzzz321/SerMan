/********************************************************************************
** Form generated from reading UI file 'sermanwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERMANWINDOW_H
#define UI_SERMANWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionConnect;
    QAction *actionDisconnect;
    QAction *actionCleanup;
    QAction *actionClear_Terminal;
    QAction *action_Load_Commands;
    QAction *actionShortCuts;
    QAction *actiontestar;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLineEdit *cmdLineEdit;
    QTextEdit *logEdit;
    QPushButton *sendButton;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menu_Help;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QStringLiteral("actionConnect"));
        actionDisconnect = new QAction(MainWindow);
        actionDisconnect->setObjectName(QStringLiteral("actionDisconnect"));
        actionCleanup = new QAction(MainWindow);
        actionCleanup->setObjectName(QStringLiteral("actionCleanup"));
        actionClear_Terminal = new QAction(MainWindow);
        actionClear_Terminal->setObjectName(QStringLiteral("actionClear_Terminal"));
        action_Load_Commands = new QAction(MainWindow);
        action_Load_Commands->setObjectName(QStringLiteral("action_Load_Commands"));
        actionShortCuts = new QAction(MainWindow);
        actionShortCuts->setObjectName(QStringLiteral("actionShortCuts"));
        actiontestar = new QAction(MainWindow);
        actiontestar->setObjectName(QStringLiteral("actiontestar"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        cmdLineEdit = new QLineEdit(centralWidget);
        cmdLineEdit->setObjectName(QStringLiteral("cmdLineEdit"));

        gridLayout->addWidget(cmdLineEdit, 2, 0, 1, 1);

        logEdit = new QTextEdit(centralWidget);
        logEdit->setObjectName(QStringLiteral("logEdit"));
        QFont font;
        font.setFamily(QStringLiteral("DejaVu Sans Mono"));
        font.setPointSize(9);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        logEdit->setFont(font);
        logEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        logEdit->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        logEdit->setReadOnly(true);

        gridLayout->addWidget(logEdit, 0, 0, 1, 2);

        sendButton = new QPushButton(centralWidget);
        sendButton->setObjectName(QStringLiteral("sendButton"));

        gridLayout->addWidget(sendButton, 2, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 22));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        menu_Help = new QMenu(menuBar);
        menu_Help->setObjectName(QStringLiteral("menu_Help"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_File->menuAction());
        menuBar->addAction(menu_Help->menuAction());
        menu_File->addAction(actionConnect);
        menu_File->addAction(actionDisconnect);
        menu_File->addAction(actionCleanup);
        menu_File->addAction(actionClear_Terminal);
        menu_File->addAction(action_Load_Commands);
        menu_Help->addAction(actionShortCuts);
        mainToolBar->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Serman", Q_NULLPTR));
        actionConnect->setText(QApplication::translate("MainWindow", "&Connect", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionConnect->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionDisconnect->setText(QApplication::translate("MainWindow", "&Disconnect", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionDisconnect->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionCleanup->setText(QApplication::translate("MainWindow", "C&leanup", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionCleanup->setShortcut(QApplication::translate("MainWindow", "Ctrl+L", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionClear_Terminal->setText(QApplication::translate("MainWindow", "Clear Terminal", Q_NULLPTR));
        action_Load_Commands->setText(QApplication::translate("MainWindow", "&Load Commands", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        action_Load_Commands->setShortcut(QApplication::translate("MainWindow", "Ctrl+T", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionShortCuts->setText(QApplication::translate("MainWindow", "ShortCuts", Q_NULLPTR));
        actiontestar->setText(QApplication::translate("MainWindow", "testar", Q_NULLPTR));
        sendButton->setText(QApplication::translate("MainWindow", "Send", Q_NULLPTR));
        menu_File->setTitle(QApplication::translate("MainWindow", "&File", Q_NULLPTR));
        menu_Help->setTitle(QApplication::translate("MainWindow", "&Help", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERMANWINDOW_H
