#ifndef SRC_CREDIT_CREDIT_RESULT_H_
#define SRC_CREDIT_CREDIT_RESULT_H_
#include <QWidget>
#include "Model_and_Controller/controller.h"

namespace Ui {
class Credit_result;
}
namespace s21 {
class Credit_result : public QWidget {
  Q_OBJECT
 public:
  explicit Credit_result(QWidget *parent = nullptr);
  ~Credit_result();
 public slots:
  void slot_credit_res(std::array<double, nums_of_output_date> array_res, bool flag_type_payment);
 private:
  Ui::Credit_result *ui;
};
}  //  namespace s21
#endif  //  SRC_CREDIT_CREDIT_RESULT_H_
