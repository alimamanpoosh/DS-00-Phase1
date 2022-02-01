#ifndef POLL_H
#define POLL_H

#include <QWidget>

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlQueryModel>

namespace Ui {
class poll;
}

class poll : public QWidget
{
    Q_OBJECT

public:
    explicit poll(QWidget *parent = nullptr);
    ~poll();

private slots:

    void on_pushButton_2_clicked();

    void on_Like_it_button_clicked();

    void on_dont_like_button_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_show_video_clicked();

private:
    Ui::poll *ui;
};

#endif // POLL_H
