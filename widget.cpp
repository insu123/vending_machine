#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

int money = 0;
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::change_money(int n){
    QMessageBox msg;

    money += n;
    if(money < 0){
        msg.information(nullptr,"nono","nono");
        money -= n;
    }
    ui->lcdNumber->display(money);

}

void Widget::on_pb10_clicked()
{
    change_money(10);
}

void Widget::on_pb50_clicked()
{
    change_money(50);
}

void Widget::on_pb100_clicked()
{
    change_money(100);
}

void Widget::on_pb500_clicked()
{
    change_money(500);
}

void Widget::on_pbCoffee_clicked()
{
    change_money(-100);
}

void Widget::on_pbTea_clicked()
{
    change_money(-150);
}

void Widget::on_pbCoke_clicked()
{
    change_money(-200);
}

void Widget::on_pbReset_clicked()
{
    QMessageBox msg;
    int money_500, money_100, money_50, money_10;

    money_500 = money/500;
    money %= 500;
    money_100 = money/100;
    money %= 100;
    money_50 = money/50;
    money %= 50;
    money_10 = money/10;


    msg.information(nullptr,"RESET","500 : " + QString::number(money_500) + "\n100 : " + QString::number(money_100) +
                    "\n50 : " + QString::number(money_50) + "\n10 : " + QString::number(money_10));
    money = 0;
    ui->lcdNumber->display(money);
}
