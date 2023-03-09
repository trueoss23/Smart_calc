#include <gtest/gtest.h>
#include "Model_and_Controller/controller.cpp"
#include <math.h>

TEST(oparaion_suits, one_value_0) {
  s21::Controller controller;
  const char s[] = "5";
  controller.add_full_string_in_model(s);
  const std::string res_str(controller.get_result());
  ASSERT_EQ(res_str, "5.000000");
}

TEST(oparaion_suits, one_value_1) {
  s21::Controller controller;
  const char s[] = "5";
  controller.add_full_string_in_model(s);
  const std::string res_str(controller.get_result());
  ASSERT_EQ(res_str, "5.000000");
}

TEST(oparaion_suits, logs) {
  s21::Controller controller;
  const char s[] = "(ln2-log10)";
  controller.add_full_string_in_model(s);
  const std::string res_str(controller.get_result());
  ASSERT_EQ(res_str, "-0.306853");
}

TEST(oparaion_suits, operations_exp) {
  s21::Controller controller;
  const char s[] = "2^3^4";
  controller.add_full_string_in_model(s);
  const std::string res_str(controller.get_result());
  ASSERT_EQ(res_str, "2417851639229258349412352.000000");
}

TEST(oparaion_suits, operations_sum) {
  s21::Controller controller;
  const char s[] = "2+3-4";
  controller.add_full_string_in_model(s);
  const std::string res_str(controller.get_result());
  ASSERT_EQ(res_str, "1.000000");
}

TEST(oparaion_suits, operations_mul) {
  s21::Controller controller;
  const char s[] = "2*3*4";
  controller.add_full_string_in_model(s);
  const std::string res_str(controller.get_result());
  ASSERT_EQ(res_str, "24.000000");
}

TEST(oparaion_suits, operations_div) {
  s21::Controller controller;
  const char s[] = "2/8/5";
  controller.add_full_string_in_model(s);
  const std::string res_str(controller.get_result());
  ASSERT_EQ(res_str, "0.050000");
}

TEST(oparaion_suits, operations_all_operations_0) {
  s21::Controller controller;
  const char s[] = "2^3+1*4";
  controller.add_full_string_in_model(s);
  const std::string res_str(controller.get_result());
  ASSERT_EQ(res_str, "12.000000");
}

TEST(oparaion_suits, operations_all_operations_1) {
  s21::Controller controller;
  const char s[] = "2-3^2/3*5+100";
  controller.add_full_string_in_model(s);
  const std::string res_str(controller.get_result());
  ASSERT_EQ(res_str, "87.000000");
}

TEST(oparaion_suits, sin) {
  s21::Controller controller;
  const char s[] = "sin2";
  controller.add_full_string_in_model(s);
  const std::string res_str(controller.get_result());
  ASSERT_EQ(res_str, "0.909297");
}

TEST(oparaion_suits, cos) {
  s21::Controller controller;
  const char s[] = "cos(-20214)";
  controller.add_full_string_in_model(s);
  const std::string res_str(controller.get_result());
  ASSERT_EQ(res_str, "0.546291");
}

TEST(oparaion_suits, tan) {
  s21::Controller controller;
  const char s[] = "tan(3^1.5)";
  controller.add_full_string_in_model(s);
  const std::string res_str(controller.get_result());
  ASSERT_EQ(res_str, "-1.903298");
}

TEST(oparaion_suits, atan_acos_asin) {
  s21::Controller controller;
  const char s[] = "asin1-acos0+atan1";
  controller.add_full_string_in_model(s);
  const std::string res_str(controller.get_result());
  ASSERT_EQ(res_str, "0.785398");
}

TEST(oparaion_suits, e) {
  s21::Controller controller;
  const char s[] = "3e+2/10^2";
  controller.add_full_string_in_model(s);
  const std::string res_str(controller.get_result());
  ASSERT_EQ(res_str, "3.000000");
}

TEST(oparaion_suits, unari_operations_0) {
  s21::Controller controller;
  const char s[] = "+++++-5---3-+-++7";
  controller.add_full_string_in_model(s);
  const std::string res_str(controller.get_result());
  ASSERT_EQ(res_str, "-1.000000");
}

TEST(oparaion_suits, unari_operations_1) {
  s21::Controller controller;
  const char s[] = "-sqrt(+4)+sin(-0)";
  controller.add_full_string_in_model(s);
  const std::string res_str(controller.get_result());
  ASSERT_EQ(res_str, "-2.000000");
}

TEST(oparaion_suits, unari_operations_2) {
  s21::Controller controller;
  const char s[] = "2^++---1*4";
  controller.add_full_string_in_model(s);
  const std::string res_str(controller.get_result());
  ASSERT_EQ(res_str, "2.000000");
}

TEST(oparaion_suits, border_case_0) {
  s21::Controller controller;
  const char s[] = "1/0";
  controller.add_full_string_in_model(s);
  const std::string res_str(controller.get_result());
  ASSERT_EQ(res_str, "inf");
}

TEST(oparaion_suits, border_case_1) {
  s21::Controller controller;
  const char s[] = "0/0";
  controller.add_full_string_in_model(s);
  const std::string res_str(controller.get_result());
  ASSERT_EQ(res_str, "nan");
}

TEST(oparaion_suits, border_case_2) {
  s21::Controller controller;
  const char s[] = "sqrt(-1)";
  controller.add_full_string_in_model(s);
  const std::string res_str(controller.get_result());
  ASSERT_EQ(res_str, "nan");
}

TEST(oparaion_suits, border_case_3) {
  s21::Controller controller;
  const char s[] = "ln(0)";
  controller.add_full_string_in_model(s);
  const std::string res_str(controller.get_result());
  ASSERT_EQ(res_str, "-inf");
}

TEST(oparaion_suits, border_case_4) {
  s21::Controller controller;
  const char s[] = "1mod0";
  controller.add_full_string_in_model(s);
  const std::string res_str(controller.get_result());
  ASSERT_EQ(res_str, "nan");
}

TEST(oparaion_suits, mod_0) {
  s21::Controller controller;
  const char s[] = "2mod3";
  controller.add_full_string_in_model(s);
  const std::string res_str(controller.get_result());
  ASSERT_EQ(res_str, "2.000000");
}

TEST(oparaion_suits, mod_1) {
  s21::Controller controller;
  const char s[] = "-3mod2";
  controller.add_full_string_in_model(s);
  const std::string res_str(controller.get_result());
  ASSERT_EQ(res_str, "-1.000000");
}

TEST(oparaion_suits, clean_last_elem_0) {
  s21::Controller controller;
  const char s[] = "-3mod23";
  controller.add_full_string_in_model(s);
  controller.delete_last_elem_in_model();
  const std::string res_str(controller.get_result());
  ASSERT_EQ(res_str, "-1.000000");
}

TEST(oparaion_suits, clean_last_elem_1) {
  s21::Controller controller;
  const char s[] = "42";
  controller.add_full_string_in_model(s);
  controller.delete_last_elem_in_model();
  controller.delete_last_elem_in_model();
  const std::string res_str(controller.get_result());
  ASSERT_EQ(res_str, "0.000000");
}

TEST(oparaion_suits, clean_last_elem_2) {
  s21::Controller controller;
  const char s[] = "cos";
  controller.add_full_string_in_model(s);
  controller.delete_last_elem_in_model();
  controller.delete_last_elem_in_model();
  const std::string res_str(controller.get_result());
  ASSERT_EQ(res_str, "0.000000");
}

TEST(oparaion_suits, clear) {
  s21::Controller controller;
  const char s[] = "-3mod2";
  controller.add_full_string_in_model(s);
  controller.reset();
  controller.add_full_string_in_model(s);
  const std::string res_str(controller.get_result());
  ASSERT_EQ(res_str, "-1.000000");
}

TEST(oparaion_suits, x_and_brace_0) {
  s21::Controller controller;
  const char s[] = "51(x)";
  controller.set_x_in_model(2);
  controller.add_full_string_in_model(s);
  const std::string res_str(controller.get_result());
  ASSERT_EQ(res_str, "102.000000");
}

TEST(oparaion_suits, x_and_brace_1) {
  s21::Controller controller;
  const char s[] = "(x)51";
  controller.set_x_in_model(2);
  controller.add_full_string_in_model(s);
  const std::string res_str(controller.get_result());
  ASSERT_EQ(res_str, "102.000000");
}

TEST(oparaion_suits, credit_an_type) {
  std::array<double, 4> arr_res;
  std::array<double, 4> arr_calc;
  s21::Controller controller;
  controller.set_credit_info(100000, 10, 12, 1);
  arr_calc = controller.get_res_credit_in_model();
  arr_res[2] = 105582;
  arr_res[1] = 5582.08;
  arr_res[0] = 10558.2;
  ASSERT_TRUE(fabs(arr_res[0] - arr_calc[0]) < 1e-2);
  ASSERT_TRUE(fabs(arr_res[1] - arr_calc[1]) < 1e-2);
  ASSERT_TRUE(fabs(arr_res[2] - arr_calc[2]) < 1e-1);
}

TEST(oparaion_suits, credit_diff_type) {
  std::array<double, 4> arr_res;
  std::array<double, 4> arr_calc;
  s21::Controller controller;
  controller.set_credit_info(100000, 10, 12, 0);
  arr_calc = controller.get_res_credit_in_model();
  arr_res[3] = 10100;
  arr_res[2] = 105500;
  arr_res[1] = 5500;
  arr_res[0] = 11000;
  ASSERT_TRUE(fabs(arr_res[0] - arr_calc[0]) < 1e-1);
  ASSERT_TRUE(fabs(arr_res[1] - arr_calc[1]) < 1e-1);
  ASSERT_TRUE(fabs(arr_res[2] - arr_calc[2]) < 1e-1);
  ASSERT_TRUE(fabs(arr_res[3] - arr_calc[3]) < 1e-1);
}

TEST(oparaion_suits, x_0) {
  s21::Controller controller;
  const char s[] = "x+5";
  controller.add_full_string_in_model(s);
  controller.reset();
  controller.add_full_string_in_model(s);
  const std::string res_str(controller.get_result());
  ASSERT_EQ(res_str, "5.000000");
}

TEST(oparaion_suits, x_1) {
  s21::Controller controller;
  const char s[] = "x+52";
  controller.set_x_in_model(-3);
  controller.add_full_string_in_model(s);
  const std::string res_str(controller.get_result());
  ASSERT_EQ(res_str, "49.000000");
}

TEST(oparaion_suits, x_2) {
  s21::Controller controller;
  const char s[] = "51.3x-50.3x";
  controller.set_x_in_model(2);
  controller.add_full_string_in_model(s);
  const std::string res_str(controller.get_result());
  ASSERT_EQ(res_str, "2.000000");
}

TEST(oparaion_suits, x_3) {
  s21::Controller controller;
  controller.set_x_in_model(2);
  controller.add_full_string_in_model("xx");
  const std::string res_str(controller.get_result());
  ASSERT_EQ(res_str, "4.000000");
}

TEST(oparaion_suits, x_4) {
  s21::Controller controller;
  controller.set_x_in_model(2);
  controller.add_full_string_in_model("x^++2");
  const std::string res_str(controller.get_result());
  ASSERT_EQ(res_str, "4.000000");
}

TEST(oparaion_suits, error_0) {
  s21::Controller controller;
  const char s[] = "-sqrt(+4)+sin(-0";
  controller.add_full_string_in_model(s);
  EXPECT_ANY_THROW(controller.get_result());
}

TEST(oparaion_suits, error_1) {
  s21::Controller controller;
  const char s[] = "(((2-321312))))";
  controller.add_full_string_in_model(s);
  EXPECT_ANY_THROW(controller.get_result());
}

TEST(oparaion_suits, error_2) {
  s21::Controller controller;
  const char s[] = "124214+";
  controller.add_full_string_in_model(s);
  EXPECT_ANY_THROW(controller.get_result());
}

TEST(oparaion_suits, error_3) {
  s21::Controller controller;
  const char s[] = ")124214+4";
  controller.add_full_string_in_model(s);
  EXPECT_FALSE(controller.check_str());
}

int main(int argc, char *argv[]) {
::testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();
}
