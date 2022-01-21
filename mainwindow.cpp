#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QString>

double num_first;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_number()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_number()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_number()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_number()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_number()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_number()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_number()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_number()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_number()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_number()));
    connect(ui->pushButton_sign, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_percent, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_clear, SIGNAL(clicked()), this, SLOT(on_pushButton_clear_clicked()));
    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_multpl, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_equal, SIGNAL(clicked()), this, SLOT(on_pushButton_clear_clicked()));

    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_multpl->setCheckable(true);
    ui->pushButton_div->setCheckable(true);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_number()
{
    QPushButton* button = (QPushButton*)sender();
    QString new_label;
    double all_numbers;
    if(ui->result_show->text().contains(".") && button->text() == "0"){
        new_label = ui->result_show->text() + "0";
        ui->result_show->setText(new_label);
    } else if(ui->result_show->text() == QString::number(num_first)){
        ui->result_show->setText(button->text());
    } else {
        all_numbers = (ui->result_show->text() + button->text()).toDouble();
        new_label = QString::number(all_numbers, 'g', 15);
        ui->result_show->setText(new_label);
    }

}


void MainWindow::on_pushButton_dot_clicked()
{
    if(!ui->result_show->text().contains('.')){
        ui->result_show->setText(ui->result_show->text() + ".");
    }

}
void MainWindow::operations()
{
    QPushButton* button = (QPushButton*)sender();

    double all_numbers = 0;

    if(button->text() == "+/-"){
        all_numbers = (ui->result_show->text()).toDouble();
        all_numbers *= (-1);
    } else if(button->text() == "%"){
        all_numbers = (ui->result_show->text()).toDouble();
        all_numbers *= 0.01;
    }
    QString new_label = QString::number(all_numbers, 'g', 15);
    ui->result_show->setText(new_label);
}


void MainWindow::on_pushButton_clear_clicked()
{
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_div->setChecked(false);
    ui->pushButton_multpl->setChecked(false);
    QPushButton* button = (QPushButton*)sender();
    if(button->text() == "AC"){
        ui->result_show->setText("0");
    }
}


void MainWindow::on_pushButton_equal_clicked()
{
    double label_number = ui->result_show->text().toDouble(), num_second;

    num_second = ui->result_show->text().toDouble();

    if(ui->pushButton_plus->isChecked()){
        label_number = num_first + num_second;

        ui->pushButton_plus->setChecked(false);
    } else if(ui->pushButton_minus->isChecked()){
        label_number = num_first - num_second;

        ui->pushButton_minus->setChecked(false);
    } else if(ui->pushButton_div->isChecked()){
        if(ui->result_show->text() == "0"){
            ui->result_show->setText("0");
        }else{
            label_number = num_first / num_second;
        }

        ui->pushButton_div->setChecked(false);
    } else if(ui->pushButton_multpl->isChecked()){
        label_number = num_first * num_second;

        ui->pushButton_multpl->setChecked(false);
    } else {}
    QString new_label = QString::number(label_number, 'g', 15);
    ui->result_show->setText(new_label);

}
bool itContains(QString str)    //check for '+', '-', '*', '/'
{
    for(const auto &now : str){
        if(now == '+' || now == '-' || now == 'x' || now == '/') return true;
    }
    return false;
}

void MainWindow::math_operations()
{
    QPushButton* button = (QPushButton*)sender();

    num_first = ui->result_show->text().toDouble();
    if(!itContains(button->text())) {
        ui->result_show->setText(button->text());
    }

    button->setChecked(true);
}

