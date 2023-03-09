#ifndef SRC_SET_GRAFF_BORDER_H_
#define SRC_SET_GRAFF_BORDER_H_
#include <QWidget>
#include"graff.h"

namespace Ui {
class Set_graff_border;
}
namespace s21 {
class Set_graff_border : public QWidget {
  Q_OBJECT
 public:
  QString res_str;
  explicit Set_graff_border(QString str = nullptr, QWidget *parent = nullptr);
  ~Set_graff_border();
  double xB, xE, yB, yE;
  QString str_from_main;
 public slots:
  void on_pushButton_clicked();
signals:
  void borders_graff(double, double, double, double);
 private:
  Ui::Set_graff_border *ui;
  s21::Graff *graff;
};
}  //  namespace s21

#endif  //  SRC_SET_GRAFF_BORDER_H_

