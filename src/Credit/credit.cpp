#include "credit.h"
#include "ui_credit.h"

s21::credit::credit(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::credit) {
  ui->setupUi(this);
}

s21::credit::~credit() {
    delete ui;
}

std::array<double, s21::nums_of_output_date> s21::credit::get_res_array() {
    Controller controller_in_credit;
    bool type = ui->radioButton_annu->isChecked() ? true : false;
    controller_in_credit.set_credit_info(ui->spinBox_sum->value(), ui->spinBox_time->value(),
                                   ui->doubleSpinBox_percent->value(), type);
    return controller_in_credit.get_res_credit_in_model();
}

void s21::credit::on_pushButton_clicked() {
  bool type = ui->radioButton_annu->isChecked() ? true : false;
  credit_result = new s21::Credit_result;
  credit_result->setAttribute(Qt::WA_DeleteOnClose);
  connect(this, &credit::signal_credit_result, credit_result, &Credit_result::slot_credit_res);
  std::array<double, nums_of_output_date> array_temp = get_res_array();
//  controller_in_credit.reset();
  emit signal_credit_result(array_temp, type);
  close();
}
