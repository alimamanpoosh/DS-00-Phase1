#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "form.h"
#include "poll.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Button_singin_clicked();

    void on_Button_login_clicked();

    void on_Button_close_clicked();

    void on_Button_minimize_clicked();

private:
    Ui::MainWindow *ui;
    Form form;
    poll poll;
};
#endif // MAINWINDOW_H
