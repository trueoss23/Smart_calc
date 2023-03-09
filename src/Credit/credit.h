#ifndef SRC_CREDIT_CREDIT_H_
#define SRC_CREDIT_CREDIT_H_
#include <QDialog>
#include "credit_result.h"

namespace Ui {
class credit;
}

namespace s21 {
class credit : public QDialog {
  Q_OBJECT

 public:
  explicit credit(QWidget *parent = nullptr);
  ~credit();

 private:
  Ui::credit *ui;
  s21::Credit_result *credit_result;
  std::array<double, nums_of_output_date> get_res_array();
 signals:
  void signal_credit_result(std::array<double, nums_of_output_date> array_res, bool flag_type_payment);
 private slots:
  void on_pushButton_clicked();
};
}  //  namespace s21
#endif  //  SRC_CREDIT_CREDIT_H_
