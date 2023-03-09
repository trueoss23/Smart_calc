#include "set_x.h"
#include "ui_set_x.h"

s21::Set_x::Set_x(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Set_x) {
    ui->setupUi(this);
}

s21::Set_x::~Set_x() {
    delete ui;
}

void s21::Set_x::on_pushButton_clicked() {
    emit signal_set_x(ui->doubleSpinBox->value());
    close();
}
