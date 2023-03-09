#ifndef SRC_SET_X_H
#define SRC_SET_X_H
#include <QWidget>

namespace Ui {
class Set_x;
}

namespace s21 {
class Set_x : public QWidget {
  Q_OBJECT
 public:
  explicit Set_x(QWidget *parent = nullptr);
  ~Set_x();
 private:
  Ui::Set_x *ui;
 signals:
  void signal_set_x(double x);
 private slots:
  void on_pushButton_clicked();
};
}  //  namespace s21
#endif  //  SRC_SET_X_H
