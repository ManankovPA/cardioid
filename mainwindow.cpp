#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include <QElapsedTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->spinBox, static_cast<void(QSpinBox::*)(int)> (&QSpinBox::valueChanged), this, [this](int value){ui->widget->setnumerator(value);});
    connect(ui->spinBox_2, static_cast<void(QSpinBox::*)(int)> (&QSpinBox::valueChanged), this, [this](int value){ui->widget->setdenumerator(value);});
}

MainWindow::~MainWindow()
{
    delete ui;
}





