#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSerialPort>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_red_slider_valueChanged(int value);

    void on_green_slider_valueChanged(int value);

    void on_blue_slider_valueChanged(int value);

private:
    Ui::Dialog *ui;
    QSerialPort *arduino;
};
#endif // DIALOG_H
