#include "credit_result.h"
#include "ui_credit_result.h"

s21::Credit_result::Credit_result(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Credit_result) {
    ui->setupUi(this);
}

s21::Credit_result::~Credit_result() {
    delete ui;
}

void s21::Credit_result::slot_credit_res(std::array<double, nums_of_output_date> array_res,
                                         bool flag_type_payment) {
    ui->label_over_res->setText(QString::number(array_res[1]));
    ui->label_all_res->setText(QString::number(array_res[2]));
    if (flag_type_payment) {
        ui->label_m_res->setText(QString::number(array_res[0]));
    } else {
        ui->label_m_res->setText(QString::number(array_res[0]) + "..." + QString::number(array_res[3]));
    }
    show();
}

