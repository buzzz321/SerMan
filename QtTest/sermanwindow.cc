#include "sermanwindow.h"
#include "ui_sermanwindow.h"
#include "keyboardfilter.h"
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->logEdit->setAlignment(Qt::AlignLeft | Qt::AlignBottom);
    ui->logEdit->setVisible(true);
    ui->cmdLineEdit->installEventFilter( this );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_sendButton_clicked()
{
    commandHistory.addToHistory(ui->cmdLineEdit->text().toStdString());
    ui->cmdLineEdit->clear();

    cout << ui->cmdLineEdit->text().toStdString() << endl;
}

bool MainWindow::eventFilter( QObject *dist, QEvent *event )
{
    if( event->type() == QEvent::KeyPress )
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>( event );
        if( keyEvent->key() == Qt::Key_Up )
        {
            ui->cmdLineEdit->setText(QString(commandHistory.getFromHistory().c_str()));
            commandHistory.stepBackHistory();

            cout << "up arrow" << endl;
            return true;
        }

        if( keyEvent->key() == Qt::Key_Down )
        {
            ui->cmdLineEdit->setText(QString(commandHistory.getFromHistory().c_str()));
            commandHistory.stepForwardHistory();
            cout << "down arrow" << endl;
            return true;
        }

        if( keyEvent->key() == Qt::Key_Return )
        {
            commandHistory.addToHistory(ui->cmdLineEdit->text().toStdString());

            auto scrollBar = ui->logEdit->verticalScrollBar();
            scrollBar->setValue(scrollBar->maximumHeight());
            ui->logEdit->append(ui->cmdLineEdit->text());

            ui->cmdLineEdit->clear();
            return true;
        }
        if ( (keyEvent->key() == Qt::Key_D)&& (QApplication::keyboardModifiers() & Qt::ControlModifier)){
            for(auto line: commandHistory.dumpHistory()){
                std::cout<< line << std::endl;
            }
        }

    }

    return QObject::eventFilter(dist, event);
}
