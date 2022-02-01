#include "poll.h"
#include "ui_poll.h"


#include<QDebug>

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlQueryModel>


poll::poll(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::poll)
{
    ui->setupUi(this);

    //open database

    QSqlDatabase  db;
    db=QSqlDatabase ::addDatabase("QSQLITE");
    db.setDatabaseName("d:\\PollIMDB\\database\\list.db");
    db.open();
}

poll::~poll()
{
    delete ui;
}



//show akas & ratings for database
void poll::on_pushButton_2_clicked()
{
    QSqlQuery q;
    q.exec("SELECT * FROM akas");

    QSqlQueryModel *m=new QSqlQueryModel;
    m->setQuery(q);

    ui->tableView_3->setModel(m);


    QSqlQuery q2;
    q2.exec("SELECT * FROM ratings");
    QSqlQueryModel *model_ratings_table=new QSqlQueryModel;
    model_ratings_table->setQuery(q2);

    ui->tableView_4->setModel(model_ratings_table);
}

//increase numvotes if user like it
void poll::on_Like_it_button_clicked()
{
    QSqlQuery q_like;

    QString s;
    s=ui->lineEdit_id->text();

    q_like.exec("SELECT numVotes FROM ratings WHERE id='"+s+"' ");

    if(q_like.first())
    {
        qDebug() << q_like.value("numVotes").toInt();
        q_like.exec("UPDATE ratings SET numVotes='"+QString::number((q_like.value("numVotes").toInt()+1))+"' WHERE id='"+s+"'  ");
        ui->dont_exit_button->setText( QString::number((q_like.value(0).toInt()+1)));


    }
    else
    {
        ui->dont_exit_button->setText("                      Don't exist");
    }


}
//decrease numvote if user don't like it
void poll::on_dont_like_button_clicked()
{
    QSqlQuery q_dont_like;

    QString s;
    s=ui->lineEdit_id->text();

    q_dont_like.exec("SELECT numVotes FROM ratings WHERE id='"+s+"' ");

    if(q_dont_like.first())
    {
        qDebug() << q_dont_like.value("numVotes").toInt();
        q_dont_like.exec("UPDATE ratings SET numVotes='"+QString::number((q_dont_like.value("numVotes").toInt()-1))+"' WHERE id='"+s+"'  ");
        ui->dont_exit_button->setText( QString::number((q_dont_like.value(0).toInt()-1)));


    }
    else
    {
        ui->dont_exit_button->setText("                      Don't exist");
    }
}
//minimize window
void poll::on_pushButton_4_clicked()
{
    this->showMinimized();
}
//close window
void poll::on_pushButton_clicked()
{
    this->close();
}

//show top 10 movies
void poll::on_show_video_clicked()
{
    QSqlQuery q_video1,q_video2,q_video3,q_video4,q_video5,q_video6,q_video7,q_video8,q_video9,q_video10;
    QString s1="34",s2="31",s3="38",s4="36",s5="33",s6="30",s7="40",s8="32",s9="35",s10="37";

    //video1

    q_video1.exec("SELECT title FROM akas WHERE id='"+s1+"' ");
    if(q_video1.first())
    {

        ui->video_1_best->setText((q_video1.value(0).toString()));
    }
    else
    {
        ui->video_1_best->setText("don't exist");
    }

    //video2

    q_video2.exec("SELECT title FROM akas WHERE id='"+s2+"' ");
    if(q_video2.first())
    {

        ui->video_2_best->setText((q_video2.value(0).toString()));
    }
    else
    {
        ui->video_2_best->setText("don't exist");
    }

    //vdieo3

    q_video3.exec("SELECT title FROM akas WHERE id='"+s3+"' ");
    if(q_video3.first())
    {

        ui->video_3_best->setText((q_video3.value(0).toString()));
    }
    else
    {
        ui->video_3_best->setText("don't exist");
    }

    //vdieo4

    q_video4.exec("SELECT title FROM akas WHERE id='"+s4+"' ");
    if(q_video4.first())
    {

        ui->video_4_best->setText((q_video4.value(0).toString()));
    }
    else
    {
        ui->video_4_best->setText("don't exist");
    }

    //vdieo5

    q_video5.exec("SELECT title FROM akas WHERE id='"+s5+"' ");
    if(q_video5.first())
    {

        ui->video_5_best->setText((q_video5.value(0).toString()));
    }
    else
    {
        ui->video_5_best->setText("don't exist");
    }

    //vdieo6

    q_video6.exec("SELECT title FROM akas WHERE id='"+s6+"' ");
    if(q_video6.first())
    {

        ui->video_6_best->setText((q_video6.value(0).toString()));
    }
    else
    {
        ui->video_6_best->setText("don't exist");
    }

    //vdieo7

    q_video7.exec("SELECT title FROM akas WHERE id='"+s7+"' ");
    if(q_video7.first())
    {

        ui->video_7_best->setText((q_video7.value(0).toString()));
    }
    else
    {
        ui->video_7_best->setText("don't exist");
    }

    //vdieo8

    q_video8.exec("SELECT title FROM akas WHERE id='"+s8+"' ");
    if(q_video8.first())
    {

        ui->video_8_best->setText((q_video8.value(0).toString()));
    }
    else
    {
        ui->video_8_best->setText("don't exist");
    }

    //vdieo9

    q_video9.exec("SELECT title FROM akas WHERE id='"+s9+"' ");
    if(q_video9.first())
    {

        ui->video_9_best->setText((q_video9.value(0).toString()));
    }
    else
    {
        ui->video_9_best->setText("don't exist");
    }

    //vdieo10

    q_video10.exec("SELECT title FROM akas WHERE id='"+s10+"' ");
    if(q_video10.first())
    {

        ui->video_10_best->setText((q_video10.value(0).toString()));
    }
    else
    {
        ui->video_10_best->setText("don't exist");
    }



}
