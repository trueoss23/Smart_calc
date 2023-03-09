#include "set_graff_border.h"
#include "ui_set_graff_border.h"

s21::Set_graff_border::Set_graff_border(QString str, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Set_graff_border) {
    res_str = str;
    ui->setupUi(this);
}

s21::Set_graff_border::~Set_graff_border() {
    delete ui;
}

void s21::Set_graff_border::on_pushButton_clicked() {
    graff = new s21::Graff(res_str);
    connect(this, &Set_graff_border::borders_graff, graff, &s21::Graff::init_borders_of_graff);
    emit borders_graff(ui->doubleSpinBox_xB->value(), ui->doubleSpinBox_xE->value(),
    ui->doubleSpinBox_yB->value(), ui->doubleSpinBox_yE->value());
    this->close();
    graff->show();
}
