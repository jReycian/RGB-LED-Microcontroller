#include "dialog.h"
#include "ui_dialog.h"
#include <QtSerialPort>
#include <QSerialPortInfo>
#include <QDebug>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    arduino = new QSerialPort;

    qDebug() << "Number of available ports: " << QSerialPortInfo::availablePorts().length();
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts())
    {
        qDebug() << "\nHas vendor ID: " << serialPortInfo.hasVendorIdentifier();
        if (serialPortInfo.hasVendorIdentifier())
        {
            qDebug() << "Vendor ID: " << serialPortInfo.vendorIdentifier();
        }

        qDebug() << "Has Product ID: " << serialPortInfo.hasProductIdentifier();
        if (serialPortInfo.hasProductIdentifier())
        {
            qDebug() << "Product ID: " << serialPortInfo.productIdentifier();
        }
    }
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_red_slider_valueChanged(int value)
{
    ui->red_value->setText(QString("<span style='font-size:18pt; font-weight:600;'>%1</span>").arg(value));
}


void Dialog::on_green_slider_valueChanged(int value)
{
    ui->green_value->setText(QString("<span style='font-size:18pt; font-weight:600;'>%1</span>").arg(value));
}


void Dialog::on_blue_slider_valueChanged(int value)
{
     ui->blue_value->setText(QString("<span style='font-size:18pt; font-weight:600;'>%1</span>").arg(value));
}

