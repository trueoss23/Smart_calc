#ifndef SRC_MODEL_AND_CONTROLLER_MODEL_H_
#define SRC_MODEL_AND_CONTROLLER_MODEL_H_
#include <list>
#include <stack>
#include <iostream>
#include <array>


namespace s21 {
const int nums_of_output_date = 4;
class Model {
 private:
  const std::string *num_e_dot;
  const std::string *funcs;
  const std::string *str_plus_or_minus;
  const std::string *str_bin_operations;
  std::string str_res;
  double x_value;
  double res_of_calc;
  std::list<std::pair<std::string, int>> * model_list;
  std::list<std::pair<std::string, int>> pars_to_polskaia_notation(const std::list<std::pair<std::string,
                                                                   int>> &temp_list);
  double make_operation(double left_operand, double right_operand, std::string operation);
  std::array<double, nums_of_output_date> arr_credit;
  void annuity_payment_res(std::array<double, nums_of_output_date> * temp_arr);
  void differentiated_payment_res(std::array<double, nums_of_output_date> *temp_arr);
  void case_sim_is_num(std::string str_from_controller, const int &current_i);
  void case_sim_is_operations(std::string str_from_controller, const int &current_i);
  void case_sim_is_x();
  void case_sim_is_func(std::string str_from_controller, unsigned *current_i);
  void case_plus_minus(const std::string &lexema);
  void case_number(const std::string &lexema);
  void case_x();
  void case_operations_and_func(const std::string &lexema);
  const std::string create_str_in_sim(std::string str_from_controller, unsigned *current_i, int count);

 public:
    Model();
    ~Model();
    double cals_res(const std::list<std::pair<std::string, int>> &temp_list);
    void add_lexem_to_model_list(const std::string &str_from_controller);
    std::array<double, nums_of_output_date> calc_credit();
    void init_array_for_credit_calc(double sum, int time, double percent, bool type);
    std::string get_to_calc_result();
    void delete_last_elem();
    void clear_list();
    void set_x(double num);
    void split_str_in_lexems(const std::string &str_from_controller);
    bool check_res_str();
};
}  //  namespace s21
#endif  //  SRC_MODEL_AND_CONTROLLER_MODEL_H_
