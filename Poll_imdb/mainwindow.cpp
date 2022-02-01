#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlQueryModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Button_singin_clicked()
{
    form.show();

}
//login (serch in database)
void MainWindow::on_Button_login_clicked()
{

    QSqlQuery q_serch;

    QString user,pass;

    user=ui->username_input_box->text();
    pass=ui->password_input_box->text();

    q_serch.exec("SELECT password FROM reg WHERE username='"+user+"' ");
    if(q_serch.first())
    {
        poll.show();
    }
    else
    {
        ui->incorrect_pass->setText("incorrect pass");
    }

}
//close winndow
void MainWindow::on_Button_close_clicked()
{
    this->close();
}
//minimize window
void MainWindow::on_Button_minimize_clicked()
{
    this->showMinimized();
}
