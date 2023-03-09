#ifndef SRC_MODEL_AND_CONTROLLER_CONTROLLER_H_
#define SRC_MODEL_AND_CONTROLLER_CONTROLLER_H_
#include "model.h"

namespace s21 {
class Controller {
  Model model;
 public:
  void add_full_string_in_model(std::string str);
  std::string get_result();
  void reset();
  void delete_last_elem_in_model();
  void set_x_in_model(double x);
  void set_credit_info(double sum, int time, double percent, bool type);
  std::array<double, s21::nums_of_output_date> get_res_credit_in_model();
  bool check_str();
};
}  //  namespace s21
#endif  //  SRC_MODEL_AND_CONTROLLER_CONTROLLER_H_
