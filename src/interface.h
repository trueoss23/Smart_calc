#ifndef SRC_INTERFACE_H_
#define SRC_INTERFACE_H_

#include <QMainWindow>
#include "Model_and_Controller/model.h"
#include <list>
#include <iostream>
#include "Graff_and_set_x/set_graff_border.h"
#include "Graff_and_set_x/set_x.h"
#include "Credit/credit.h"
#include "Model_and_Controller/controller.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Interface; }
QT_END_NAMESPACE
namespace s21 {
const QString nums_e_dot("1234567890e.");
const QString str_sum = "+-";
const QString str_operations_without_sum = "*/^mod";
const QString str_func = "sincotaqrlg";
class Interface : public QMainWindow {
    Q_OBJECT

 public:
    explicit Interface(QWidget *parent = nullptr);
    ~Interface();
    std::list<std::pair<QString, int>> get_list();

 private:
    s21::Controller controller;
    QString str_in_main_label;
    std::list<QString> vision_list;
    int top_border_string_size;
    bool flag_add_enter;
    int width_label;
    void add_zero_afther_dot();
    void add_str_in_label_and_list(QString str, bool flag_add_to_end_str);
    void add_enter_in_label();
    void case_num(QPushButton *button);
    void case_x();
    void case_func(QPushButton *button);
    void case_not_sum_operations(QPushButton *button);
    void case_sum(QPushButton *button);
    Ui::Interface *ui;
    s21::Set_graff_border *set_graff_border;
    s21::Set_x *set_x;
    s21::credit *credit;
    s21::Credit_result *credit_res;
 public slots:
    void slot_set_x(double x);
 private slots:
    void on_pushButton_clear_clicked();
    void click_one_of_many_button();
    void on_pushButton_equal_clicked();
    void on_pushButton_dot_clicked();
    void on_pushButton_left_br_clicked();
    void on_pushButton_rigth_br_clicked();
    void on_pushButton_clean_clicked();
    void on_pushButton_e_clicked();
    void on_pushButton_graff_clicked();
    void on_pushButton_credit_clicked();
    void on_pushButton_dividion_set_x_clicked();
};
}  //  namespace s21
#endif  //  SRC_INTERFACE_H_
