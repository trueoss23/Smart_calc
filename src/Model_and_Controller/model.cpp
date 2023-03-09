#include "model.h"
#include <math.h>

s21::Model::Model() {
  model_list = new std::list<std::pair<std::string, int>>;
  res_of_calc = 0;
  num_e_dot = new std::string("1234567890.e");
  funcs = new std::string("sincotaqrlg");
  str_plus_or_minus = new std::string("+-");
  str_bin_operations = new std::string("/*mod");
  for (unsigned i = 0; i < arr_credit.size(); i++) {
      arr_credit[i] = 0;
  }
}
s21::Model::~Model() {
  model_list->clear();
  if (model_list != nullptr)
    delete model_list;
  if (num_e_dot != nullptr)
      delete num_e_dot;
  if (funcs != nullptr)
      delete funcs;
  if (str_plus_or_minus != nullptr)
      delete str_plus_or_minus;
  if (str_bin_operations != nullptr)
      delete str_bin_operations;
}

void s21::Model::split_str_in_lexems(const std::string &str_from_controller) {
  const std::string operations("+-*/^())");
  for (unsigned i = 0; i < str_from_controller.size(); i++) {
    if (num_e_dot->find(str_from_controller[i]) != std::string::npos) {
        case_sim_is_num(str_from_controller, i);
    } else if (operations.find(str_from_controller[i]) != std::string::npos) {
        case_sim_is_operations(str_from_controller, i);
    } else if (str_from_controller[i] == 'x') {
        case_sim_is_x();
    } else {
        case_sim_is_func(str_from_controller, &i);
    }
  }
}

void s21::Model::case_sim_is_num(std::string str_from_controller, const int &current_i) {
    if (!model_list->empty() && model_list->back().first == ")") {
      add_lexem_to_model_list("*");
    }
    if (model_list->empty() || num_e_dot->find(model_list->back().first.back()) == std::string::npos) {
      std::string temp_str = "";
      temp_str += str_from_controller[current_i];
      add_lexem_to_model_list(temp_str);
      } else {
        model_list->back().first += str_from_controller[current_i];
      }
}

void s21::Model::case_sim_is_operations(std::string str_from_controller, const int &current_i) {
    if (!model_list->empty()) {
      if (str_from_controller[current_i] == '(') {
        if (num_e_dot->find(model_list->back().first.back()) != std::string::npos ||
        model_list->back().first == "x") {
          add_lexem_to_model_list("*");
        }
      }
    }
    std::string temp_str = "";
    temp_str += str_from_controller[current_i];
    add_lexem_to_model_list(temp_str);
}

void s21::Model::case_sim_is_x() {
    if (!model_list->empty()) {
      if (num_e_dot->find(model_list->back().first.back()) != std::string::npos ||
      model_list->back().first == ")") {
        add_lexem_to_model_list("*");
      }
    }
    add_lexem_to_model_list("x");
}

void s21::Model::case_sim_is_func(std::string str_from_controller, unsigned *current_i) {
    std::string temp_str = "";
    if (str_from_controller[*current_i] == 's') {
    if (str_from_controller[*current_i + 1] == 'i') {
       temp_str = create_str_in_sim(str_from_controller, current_i, 3);
    } else {
       temp_str = create_str_in_sim(str_from_controller, current_i, 4);
    }
  } else if (str_from_controller[*current_i]== 'l') {
    if (str_from_controller[*current_i + 1] == 'o') {
        temp_str = create_str_in_sim(str_from_controller, current_i, 3);
    } else {
        temp_str = create_str_in_sim(str_from_controller, current_i, 2);
    }
  } else if (str_from_controller[*current_i] == 'a') {
        temp_str = create_str_in_sim(str_from_controller, current_i, 4);
  } else {
        temp_str = create_str_in_sim(str_from_controller, current_i, 3);
  }
  add_lexem_to_model_list(temp_str);
}

const std::string s21::Model::create_str_in_sim(std::string str_from_controller,
                                                unsigned *current_i, int length_of_lexem) {
    std::string temp_str = "";
    for (int j = 0; j < length_of_lexem; j++) {
        temp_str += str_from_controller[*current_i];
        (*current_i)++;
    }
    (*current_i)--;
    return temp_str;
}

void s21::Model::add_lexem_to_model_list(const std::string &lexema) {
  if (str_plus_or_minus->find(lexema[0]) != std::string::npos) {
        case_plus_minus(lexema);
  } else if (num_e_dot->find(lexema[0]) != std::string::npos) {
    case_number(lexema);
  } else if (lexema == "x") {
      case_x();
  } else {
      case_operations_and_func(lexema);
  }
}

void s21::Model::case_plus_minus(const std::string &lexema) {
    const std::string str_for_unar_operations("+-^/*mod(");
    int prioritet = 0;
    if (!model_list->empty() && model_list->back().first.back() == 'e') {
      model_list->back().first.append(lexema);
    } else {
      if (!model_list->empty()) {
        if (lexema == "+" &&
                str_for_unar_operations.find(model_list->back().first.back()) == std::string::npos &&
                funcs->find(model_list->back().first.back()) == std::string::npos) {
           prioritet = 1;
           std::pair<std::string, int> p_temp(lexema, prioritet);
          model_list->push_back(p_temp);
        } else if (lexema == "-") {
         if (model_list->back().first == "-" && model_list->back().second == 5) {
           model_list->pop_back();
         } else {
             if (model_list->back().second == 1 || model_list->back().first == "(" ||
                     str_for_unar_operations.find(model_list->back().first.back()) != std::string::npos ||
                     funcs->find(model_list->back().first.back()) != std::string::npos) {
               prioritet = 5;
             } else {
               prioritet = 1;
             }
             std::pair<std::string, int> p_temp(lexema, prioritet);
             model_list->push_back(p_temp);
         }
        }
      } else if (lexema == "-") {
        prioritet = 5;
        std::pair<std::string, int> p_temp(lexema, prioritet);
        model_list->push_back(p_temp);
      }
    }
}

void s21::Model::case_number(const std::string &lexema) {
    int prioritet = 0;
    if (model_list->empty() || num_e_dot->find(model_list->back().first.back()) == std::string::npos) {
      std::pair<std::string, int> p_temp(lexema, prioritet);
      model_list->push_back(p_temp);
    }
}

void s21::Model::case_x() {
    int prioritet = 0;
    std::string s = std::to_string(x_value);
    std::pair<std::string, int> p_temp(s, prioritet);
    model_list->push_back(p_temp);
}

void s21::Model::case_operations_and_func(const std::string &lexema) {
    int prioritet = 0;
    if (str_bin_operations->find(lexema[0]) != std::string::npos) {
      prioritet = 2;
    } else if (funcs->find(lexema[0]) != std::string::npos) {
      prioritet = 3;
    } else if (lexema == "^") {
      prioritet = 4;
    }
    std::pair<std::string, int> p_temp(lexema, prioritet);
    model_list->push_back(p_temp);
}

std::string s21::Model::get_to_calc_result() {
  std::string str_res;
  if (check_res_str()) {
     try {
          res_of_calc = cals_res(pars_to_polskaia_notation(*model_list));
          str_res = std::to_string(res_of_calc);
      } catch (const std::exception& stack_polsk_notation) {
          str_res = "Error calc";
      }
  } else {
    throw std::exception();
  }
  return str_res;
}

bool s21::Model::check_res_str() {
  bool res_of_check = true;
  int count_num = 0;
  int count_brace = 0;
  std::string check_str = "";
  for (auto elem : (*model_list))
      check_str.append(elem.first);
  if (!check_str.empty()) {
      for (unsigned i = 0; i < check_str.size(); i++) {
        if (num_e_dot->find(check_str[i]) != std::string::npos) {
            count_num++;
        }
        if (check_str[i] == '(') {
         count_brace++;
        } else if (check_str[i] == ')') {
           count_brace--;
        }
        if (count_brace < 0) {
           return false;
        }
      }
      std::string temp = "*/+-(^";
      if (count_brace != 0 || (count_num == 0) ||
          temp.find(check_str.back()) != std::string::npos ||
          (num_e_dot->find(check_str.back()) == std::string::npos && check_str.back() != ')')) {
         return false;
      }
  }

  return res_of_check;
}

std::list<std::pair<std::string, int>>  s21::Model::pars_to_polskaia_notation(
  const std::list<std::pair<std::string, int>> &temp_list) {
  std::stack<std::pair<std::string, int>> temp_stack;
  std::list<std::pair<std::string, int>> res_list;
  const std::string temp_str_operation = "+-^/*";
  for (auto it = temp_list.begin(); it != temp_list.end(); it++) {
  if (num_e_dot->find((*it).first.back()) != std::string::npos) {
      res_list.push_back(*it);
    } else if ((*it).first == "(" || (*it).first.size() > 1) {
      temp_stack.push(*it);
    } else if (temp_str_operation.find((*it).first.back()) != std::string::npos) {
      while (!temp_stack.empty() && temp_stack.top().second >= (*it).second) {
        if (temp_stack.top().second == 4 && (*it).second == 4)
          break;
        res_list.push_back(temp_stack.top());
        temp_stack.pop();
      }
      temp_stack.push(*it);
    } else if ((*it).first == ")") {
      while (!temp_stack.empty() && temp_stack.top().first != "(") {
        res_list.push_back(temp_stack.top());
        temp_stack.pop();
      }
      temp_stack.pop();
      if (!temp_stack.empty() &&
      funcs->find(temp_stack.top().first.back()) != std::string::npos) {
        res_list.push_back(temp_stack.top());
        temp_stack.pop();
      }
    }
  }
  while (!temp_stack.empty()) {
    if (num_e_dot->find(temp_stack.top().first.back()) == std::string::npos) {
      res_list.push_back(temp_stack.top());
      temp_stack.pop();
    } else {
        throw std::exception();
    }
  }
  return res_list;
}

double s21::Model::cals_res(const std::list<std::pair<std::string, int>> &temp_list) {
  std::stack<double> res_stack;
  for (auto elem : temp_list) {
    if (elem.second == 0) {
      res_stack.push(std::stold(elem.first));
    } else {
      double right_operand = 0;
      double left_operand = 0;
      if (elem.second == 1 || elem.second == 2 || elem.second == 4 || elem.first == "mod") {
        right_operand = res_stack.top();
        res_stack.pop();
        left_operand = res_stack.top();
        res_stack.pop();
      } else if (elem.second == 3 || elem.second == 5) {
        right_operand = res_stack.top();
        res_stack.pop();
        left_operand = 0;
      }
       double temp_res = make_operation(left_operand, right_operand, elem.first);
       res_stack.push(temp_res);
    }
  }
  return res_stack.top();
}


double s21::Model::make_operation(double left_operand, double right_operand, std::string operation) {
  double res = 0;
  if (operation == "sin") {
    res = sin(right_operand);
  } else if (operation == "cos") {
    res = cos(right_operand);
  } else if (operation == "tan") {
    res = tan(right_operand);
  } else if (operation == "asin") {
    res = asin(right_operand);
  } else if (operation == "acos") {
    res = acos(right_operand);
  } else if (operation == "atan") {
    res = atan(right_operand);
  } else if (operation == "ln") {
    res = log(right_operand);
  } else if (operation == "log") {
    res = log10(right_operand);
  } else if (operation == "sqrt") {
    res = sqrt(right_operand);
  } else if (operation == "mod") {
    res = fmod(left_operand, right_operand);
  } else if (operation == "+") {
    res = left_operand + right_operand;
  } else if (operation == "-") {
    res = left_operand - right_operand;
  } else if (operation == "*") {
    res = left_operand * right_operand;
  } else if (operation == "/") {
    res = left_operand / right_operand;
  } else if (operation == "^") {
    res = pow(left_operand, right_operand);
  }
  return res;
}

void s21::Model::delete_last_elem() {
  if (!model_list->empty()) {
    std::string temp_str_num = "1234567890e.";
    if (temp_str_num.find(model_list->back().first.back()) != std::string::npos) {
      model_list->back().first.pop_back();
      if (model_list->back().first.empty()) {
        model_list->pop_back();
      }
    } else {
      model_list->pop_back();
    }
  }
}

void s21::Model::clear_list() {
  res_of_calc = 0;
  model_list->clear();
  for (unsigned i = 0; i < arr_credit.size(); i++) {
      arr_credit[i] = 0;
  }
}

void s21::Model::init_array_for_credit_calc(double sum, int time, double percent, bool type) {
  arr_credit[0] = sum;
  arr_credit[1] = time;
  arr_credit[2] = percent;
  arr_credit[3] = type;
}

std::array<double, s21::nums_of_output_date> s21::Model::calc_credit() {
  std::array<double, nums_of_output_date> res;
  if (arr_credit[3]) {
    annuity_payment_res(&res);
  } else {
    differentiated_payment_res(&res);
  }
  return res;
}

void s21::Model::annuity_payment_res(std::array<double, nums_of_output_date> *temp_arr) {
  const double Sum = arr_credit[0];
  const double months = arr_credit[1];
  const double rate = arr_credit[2] / 12 / 100;
  double mount_payment = 0;
  if (rate != 0) {
      mount_payment = Sum * (rate * pow((1 + rate), months)) / (pow(1 + rate, months) - 1);
  } else {
      mount_payment = Sum / months;
  }

  (*temp_arr)[0] = mount_payment;
  (*temp_arr)[2] = (*temp_arr)[0] * arr_credit[1];
  (*temp_arr)[1] = (*temp_arr)[2] - arr_credit[0];
}

void s21::Model::differentiated_payment_res(std::array<double, nums_of_output_date> *temp_arr) {
  const double Sum = arr_credit[0];
  const double months = arr_credit[1];
  const double rate = arr_credit[2] / 12 / 100;
  double sum = 0;
  for (int paid_months = 0; paid_months < months; paid_months++) {
    double temp = Sum / months + (Sum - (Sum / months) * paid_months) * rate;
    if (paid_months == 0) {
      (*temp_arr)[0] = temp;
    } else if (paid_months == months - 1) {
      (*temp_arr)[3] = temp;
    }
    sum += temp;
  }
  (*temp_arr)[2] = sum;
  (*temp_arr)[1] = (*temp_arr)[2] - arr_credit[0];
}

void s21::Model::set_x(double num) {
    x_value = num;
}
