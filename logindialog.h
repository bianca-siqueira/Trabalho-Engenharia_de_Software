#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QString>
#include <QObject>
#include <QAction>
#include <QIcon>
#include "backend/autenticador.h"       //Verificar se o usuario é valido

namespace Ui
{
    class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

    public:
        explicit LoginDialog(QWidget *parent = nullptr);
        ~LoginDialog();

    signals:
        void loggedIn(const QString& username);  //Sinal emitido quando login é bem sucedido

    private slots:
        void on_entrarButton_clicked();

    private:
        Ui::LoginDialog *ui;
        Autenticador autenticador;      //Verifica se o usuario e a senha estão no banco do servidor
};

#endif // LOGINDIALOG_H
