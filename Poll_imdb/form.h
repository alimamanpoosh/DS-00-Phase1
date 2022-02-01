#ifndef FORM_H
#define FORM_H
#include "poll.h"
#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

private slots:
    void on_singUpButton_clicked();

    void on_Button_minimize_clicked();

    void on_Button_close_clicked();

private:
    Ui::Form *ui;
    poll poll;
};

#endif // FORM_H
