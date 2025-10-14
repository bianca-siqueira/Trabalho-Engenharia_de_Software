#include "mainwindow.h"
#include "logindialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginDialog loginDialog;
    MainWindow mainWindow;

    QObject::connect(&loginDialog, &LoginDialog::loggedIn,&mainWindow, &MainWindow::setLoggedInUser);
    QObject::connect(&loginDialog, &LoginDialog::loggedIn,&mainWindow, &MainWindow::show);

    if(loginDialog.exec() == QDialog::Accepted)
    {
        return a.exec();
    }
    else
    {
        return 0;
    }

    return a.exec();
}
