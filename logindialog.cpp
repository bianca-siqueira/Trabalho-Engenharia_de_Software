#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>
#include <QLineEdit>
#include <QPushButton>

LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    setWindowTitle("Rede Paradise Hotéis - Login");
    this->setStyleSheet("QDialog {background-color: #F8F8F8;}");


    //Para a pessoa conseguir ver a senha
    QAction *toggleVisibilityAction = ui->line_senha->addAction(QIcon(":/icons/of.png"), // Ícone inicial: olho fechado (esconder senha)
        QLineEdit::TrailingPosition // Posição do botão: no final do campo de texto
        );

    connect(toggleVisibilityAction, &QAction::triggered, this, [this, toggleVisibilityAction]()
    {
        // Alterna o EchoMode (se a senha está visível ou escondida)
        if (ui->line_senha->echoMode() == QLineEdit::Normal)
        {
            // Se está normal (visível)
            ui->line_senha->setEchoMode(QLineEdit::Password); // Esconde a senha
            toggleVisibilityAction->setIcon(QIcon(":/icons/of.png")); // Muda o ícone para olho fechado
            // Opcional: Adicione um tooltip
            toggleVisibilityAction->setToolTip("Mostrar senha");
        }
        else
        {
            // Se está em Password (escondida)
            ui->line_senha->setEchoMode(QLineEdit::Normal); // Mostra a senha
            toggleVisibilityAction->setIcon(QIcon(":/icons/oa.png")); // Muda o ícone para olho aberto
            // Opcional: Adicione um tooltip
            toggleVisibilityAction->setToolTip("Esconder senha");
        }
    });

    ui->line_senha->setEchoMode(QLineEdit::Password);
    this->setStyleSheet("QDialog {backgroun-color: #F0F8FF;}");
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_entrarButton_clicked()
{
    //Seria o mesmo que o cin
    QString username = ui->line_login->text();
    QString password = ui->line_senha->text();

    //Verifica se o usuario e senha são validos
    if(autenticador.autenticar(username.toStdString(), password.toStdString()))
    {
        QMessageBox::information(this, "Login Sucesso", "Login realizado com sucesso!!");
        emit loggedIn(username);
        accept();
    }
    //Se não for valido
    else
    {
        QMessageBox::warning(this, "Login Inválido", "Usuário ou senha errado, tente novamente");
        ui->line_login->setFocus();
        ui->line_senha->clear();
    }
}
