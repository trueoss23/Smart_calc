#ifndef SRC_GRAFF_H_
#define SRC_GRAFF_H_

#include <QWidget>
#include <iostream>
#include "Model_and_Controller/controller.h"
namespace Ui {
class Graff;
}

namespace s21 {
class Graff : public QWidget {
  Q_OBJECT

 public:
  explicit Graff(QString str = nullptr, QWidget *parent = nullptr);
  ~Graff();

 public slots:
  void init_borders_of_graff(double xB, double xE, double yB, double yE);

 private:
  QString res_str;
  double h, X, xBegin, xEnd, yBegin, yEnd;
  Ui::Graff *ui;
  Graff *graff;
  int N;
  QVector <double> x, y;
  void set_borders(double xB, double xE, double yB, double yE);
  void draw_graff();
  void init_vectors_for_graff();
};
}  //  namespace s21
#endif  //  SRC_GRAFF_H_
