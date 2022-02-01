#include "form.h"
#include "ui_form.h"

#include<QSqlQuery>
#include<QSqlDatabase>
#include<QSqlDriver>
#include<QSqlQueryModel>




Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}
//sing up(insert database)
void Form::on_singUpButton_clicked()
{

      QSqlQuery q;

      QString user,pass;
      user=ui->username_signup->text();
      pass=ui->password_singup->text();
      q.exec("INSERT INTO reg VALUES('"+user+"','"+pass+"')");

      poll.show();
      this->hide();


}

void Form::on_Button_minimize_clicked()
{
    this->showMinimized();
}

void Form::on_Button_close_clicked()
{
    this->close();
}
