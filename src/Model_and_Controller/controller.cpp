#include "controller.h"

std::string s21::Controller::get_result() {
    return model.get_to_calc_result();
}

void s21::Controller::reset() {
    model.clear_list();
}

void s21::Controller::delete_last_elem_in_model() {
    model.delete_last_elem();
}

void s21::Controller::add_full_string_in_model(std::string str) {
    model.split_str_in_lexems(str);
}

void s21::Controller::set_x_in_model(double x) {
    model.set_x(x);
}

void s21::Controller::set_credit_info(double sum, int time, double percent, bool type) {
    model.init_array_for_credit_calc(sum, time, percent, type);
}

std::array<double, s21::nums_of_output_date> s21::Controller::get_res_credit_in_model() {
    return model.calc_credit();
}

bool s21::Controller::check_str() {
    return model.check_res_str();
}
