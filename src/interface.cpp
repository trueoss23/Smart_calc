#include "interface.h"
#include "ui_interface.h"

s21::Interface::Interface(QWidget *parent)
  : QMainWindow(parent)
  , width_label(62)
  , ui(new Ui::Interface) {
  ui->setupUi(this);
  top_border_string_size = 300;
  connect(ui->pushButton_credit, SIGNAL(clicked()), this, SLOT(slot_set_x()));
  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(click_one_of_many_button()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(click_one_of_many_button()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(click_one_of_many_button()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(click_one_of_many_button()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(click_one_of_many_button()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(click_one_of_many_button()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(click_one_of_many_button()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(click_one_of_many_button()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(click_one_of_many_button()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(click_one_of_many_button()));
  connect(ui->pushButton_multi, SIGNAL(clicked()), this, SLOT(click_one_of_many_button()));
  connect(ui->pushButton_dividion, SIGNAL(clicked()), this, SLOT(click_one_of_many_button()));
  connect(ui->pushButton_exp, SIGNAL(clicked()), this, SLOT(click_one_of_many_button()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(click_one_of_many_button()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(click_one_of_many_button()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(click_one_of_many_button()));
  connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(click_one_of_many_button()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(click_one_of_many_button()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(click_one_of_many_button()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(click_one_of_many_button()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(click_one_of_many_button()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(click_one_of_many_button()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(click_one_of_many_button()));
  connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(click_one_of_many_button()));
  connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(click_one_of_many_button()));
  connect(ui->pushButton_x, SIGNAL(clicked()), this, SLOT(click_one_of_many_button()));
}

s21::Interface::~Interface() {
  delete ui;
}

void s21::Interface::add_str_in_label_and_list(QString str, bool flag_add_to_end_str) {
  if (str_in_main_label.size() < top_border_string_size) {
      if (flag_add_to_end_str) {
        vision_list.back().push_back(str);
      } else {
        vision_list.push_back(str);
      }
      str_in_main_label.append(str);
      add_enter_in_label();
      ui->show_res->setText(str_in_main_label);
  }
}

void s21::Interface::add_enter_in_label() {
  if ((str_in_main_label.size() > width_label - 5 && str_in_main_label.size() < width_label) ||
          (str_in_main_label.size() > width_label * 2 - 5 && str_in_main_label.size() < width_label * 2) ||
          (str_in_main_label.size() > width_label * 3 - 5  && str_in_main_label.size() < width_label * 3) ||
          (str_in_main_label.size() > width_label * 4 - 5  && str_in_main_label.size() < width_label * 4) ||
          (str_in_main_label.size() > width_label * 5 - 5  && str_in_main_label.size() < width_label * 5) ||
          (str_in_main_label.size() > width_label * 6 - 5  && str_in_main_label.size() < width_label * 6)) {
    if (!flag_add_enter) {
      str_in_main_label.append('\n');
      flag_add_enter = true;
    }
  } else {
    flag_add_enter = false;
  }
}

void s21::Interface::add_zero_afther_dot() {
  if (!vision_list.empty() && vision_list.back().back() == '.') {
    add_str_in_label_and_list("0", 1);
  }
}

void s21::Interface::click_one_of_many_button() {
  QPushButton *button = (QPushButton *)sender();
  if (nums_e_dot.contains(button->text().front())) {
    case_num(button);
  } else if (button->text() == "x") {
    case_x();
  } else if (str_func.contains(button->text().front())) {
    case_func(button);
  } else if (str_operations_without_sum.contains(button->text().front())) {
    case_not_sum_operations(button);
  } else if (str_sum.contains(button->text().front())) {
    case_sum(button);
  } else {
    add_zero_afther_dot();
    add_str_in_label_and_list(button->text(), 0);
  }
}

void s21::Interface::case_num(QPushButton *button) {
  if (!vision_list.empty()) {
    if (nums_e_dot.contains(vision_list.back().back())) {
      add_str_in_label_and_list(button->text(), 1);
    } else if (vision_list.back() == ")" || vision_list.back() == "x") {
       add_str_in_label_and_list("*", 0);
       add_str_in_label_and_list(button->text(), 0);
    } else if (vision_list.back().size() > 1 &&
           (vision_list.back() == "+" || vision_list.back() == "-")) {
      add_str_in_label_and_list(button->text(), 1);
    } else {
      add_str_in_label_and_list(button->text(), 0);
    }
  } else {
    add_str_in_label_and_list(button->text(), 0);
  }
}

void s21::Interface::case_x() {
  if (!vision_list.empty()) {
    add_zero_afther_dot();
    if (nums_e_dot.contains(vision_list.back().back()) || vision_list.back() == ")" ||
        vision_list.back() == "x") {
      add_str_in_label_and_list("*", 0);
    }
  }
  add_str_in_label_and_list("x", 0);
}

void s21::Interface::case_func(QPushButton *button) {
  add_zero_afther_dot();
  if (!vision_list.empty() &&(vision_list.back() == ")" ||
                 nums_e_dot.contains(vision_list.back().front()) ||
                 vision_list.back() == "x")) {
    add_str_in_label_and_list("*", 0);
  }
  add_str_in_label_and_list(button->text(), 0);
  add_str_in_label_and_list("(", 0);
}

void s21::Interface::case_not_sum_operations(QPushButton *button) {
  if (!vision_list.empty()) {
    add_zero_afther_dot();
    if (button->text() == "mod") {
        if (nums_e_dot.contains(vision_list.back().back()) ||
                vision_list.back() == ")") {
            add_str_in_label_and_list(button->text(), 0);
        }
    } else if ((vision_list.back() != "(") &&
        !str_operations_without_sum.contains(vision_list.back().front()) &&
        !str_sum.contains(vision_list.back())) {
      add_str_in_label_and_list(button->text(), 0);
    }
  }
}

void s21::Interface::case_sum(QPushButton *button) {
  if (!vision_list.empty() && vision_list.back().back() == 'e') {
    add_str_in_label_and_list(button->text(), 1);
  } else {
    add_zero_afther_dot();
    add_str_in_label_and_list(button->text(), 0);
  }
}

void s21::Interface::on_pushButton_equal_clicked() {
  if (!vision_list.empty() && !str_in_main_label.contains("x")) {
    add_zero_afther_dot();
    controller.add_full_string_in_model(str_in_main_label.toStdString());
    try {
        ui->show_res->setText(str_in_main_label + "=" + QString::fromStdString(controller.get_result()));
        controller.reset();
    } catch (const std::exception& err_calc) {
        ui->show_res->setText(str_in_main_label + " = Error calc");
        controller.reset();
    }
  }
}

void s21::Interface::on_pushButton_clear_clicked() {
  str_in_main_label = "";
  vision_list.clear();
  ui->show_res->setText("0");
  controller.reset();
}

void s21::Interface::on_pushButton_dot_clicked() {
  const QString all_operations = "+-*/^mod()";
  if (vision_list.empty() || all_operations.contains(vision_list.back().back())) {
    if (!vision_list.empty() && vision_list.back() == ")") {
      add_str_in_label_and_list("*", 0);
    }
    add_str_in_label_and_list("0.", 0);
  } else if (!vision_list.back().contains('.') && !vision_list.back().contains("e") &&
             !str_func.contains(vision_list.back().back()) &&
             vision_list.back() != "x") {
    add_str_in_label_and_list(".", 1);
  }
}

void s21::Interface::on_pushButton_left_br_clicked() {
  add_zero_afther_dot();
  if (!vision_list.empty()) {
     if (nums_e_dot.contains(vision_list.back().front()) || vision_list.back() == ")"
         || vision_list.back() == "x") {
       add_str_in_label_and_list("*", 0);
     }
  }
  add_str_in_label_and_list("(", 0);
}

void s21::Interface::on_pushButton_rigth_br_clicked() {
  QString temp_str = "(+-*/^modsincotaqrlg";
  if (!vision_list.empty()) {
    if (!temp_str.contains(vision_list.back().back()) && str_in_main_label.contains("(")) {
      add_zero_afther_dot();
      add_str_in_label_and_list(")", 0);
    }
  }
}

void s21::Interface::on_pushButton_clean_clicked() {
  if (!vision_list.empty()) {
    if (nums_e_dot.contains(vision_list.back().back())) {
      vision_list.back().resize(vision_list.back().size() - 1);
      if (vision_list.back().size() == 0) {
        vision_list.pop_back();
      }
    } else {
      vision_list.pop_back();
    }
    str_in_main_label = "";
    for (auto elem : vision_list) {
      str_in_main_label += elem;
    }
    if (str_in_main_label == "") {
      ui->show_res->setText("0");
    } else {
      ui->show_res->setText(str_in_main_label);
    }
  }
  controller.delete_last_elem_in_model();
}

void s21::Interface::on_pushButton_e_clicked() {
  QPushButton *button = (QPushButton *)sender();
  QString str_nums = "1234567890";
  add_zero_afther_dot();
  if (!vision_list.empty() && str_nums.contains(vision_list.back().back()) &&
      !vision_list.back().contains("e")) {
    add_str_in_label_and_list(button->text(), 1);
  }
}

void s21::Interface::on_pushButton_graff_clicked() {
  set_graff_border = new Set_graff_border(str_in_main_label);
  set_graff_border->setAttribute(Qt::WA_DeleteOnClose);
  controller.add_full_string_in_model(str_in_main_label.toStdString());
  if (str_in_main_label.size() > 0 && str_in_main_label.contains("x") && controller.check_str()) {
    set_graff_border->show();
  }
  controller.reset();
}

void s21::Interface::on_pushButton_credit_clicked() {
  credit = new class credit();
  credit->setAttribute(Qt::WA_DeleteOnClose);
  credit->show();
}

void s21::Interface::slot_set_x(double x) {
  controller.set_x_in_model(x);
  controller.add_full_string_in_model(str_in_main_label.toStdString());
  try {
      if (ui->show_res->text().contains("=")) {
        QString temp_str = ui->show_res->text();
        temp_str.resize(ui->show_res->text().indexOf("=") + 1);
        ui->show_res->setText(temp_str + QString::fromStdString(controller.get_result()));
      } else {
        ui->show_res->setText(ui->show_res->text() + "=" + QString::fromStdString(controller.get_result()));
      }
      controller.reset();
  } catch (const std::exception& err_calc) {
    ui->show_res->setText(str_in_main_label + " = Error calc");
    controller.reset();
  }
}


void s21::Interface::on_pushButton_dividion_set_x_clicked() {
  if (str_in_main_label.contains("x")) {
    set_x = new Set_x;
    connect(set_x, &Set_x::signal_set_x, this, &Interface::slot_set_x);
    set_x->show();
  }
}

