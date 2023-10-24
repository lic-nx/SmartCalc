#include <check.h>
#include <math.h>

#include "./calc/credit.h"
#include "./calc/s21_calc.h"

START_TEST(case_1) {
  char expression[255] = "122,1 + 877,9";
  char res[255] = {0};
  int ret = 1;
  float x = 0;
  ret = validator(expression, res);
  ck_assert_int_eq(ret, 0);
  double result = pol_notation(res, x);
  ck_assert_double_eq_tol(result, 1000.0, 1e-7);
}
END_TEST

START_TEST(case_2) {
  char expression[255] = "2,5 - 0,5";
  char res[255] = {0};
  float x = 0;
  int ret = validator(expression, res);
  ck_assert_int_eq(ret, 0);
  double result = pol_notation(res, x);
  ck_assert_double_eq_tol(result, 2.0, 1e-7);
}
END_TEST

START_TEST(case_3) {
  char expression[255] = "-1,9+(-777,1)";
  char res[255] = {0};
  float x = 0;
  int ret = validator(expression, res);
  ck_assert_int_eq(ret, 0);
  double result = pol_notation(res, x);
  ck_assert_double_eq_tol(result, -779.0, 1e-7);
}
END_TEST

START_TEST(case_4) {
  char expression[255] = "-2,12345-1000,000003";
  char res[255] = {0};
  float x = 0;
  int ret = validator(expression, res);
  ck_assert_int_eq(ret, 0);
  double result = pol_notation(res, x);
  ck_assert_double_eq_tol(result, -1002.123453, 1e-7);
}
END_TEST

START_TEST(case_5) {
  char expression[255] = "-2,78941 - (-995,258964)";
  char res[255] = {0};
  float x = 0;
  int ret = validator(expression, res);
  ck_assert_int_eq(ret, 0);
  double result = pol_notation(res, x);
  ck_assert_double_eq_tol(result, 992.469554, 1e-7);
}
END_TEST

START_TEST(case_6) {
  char expression[255] = "100000 - (-20249,654684)";
  char res[255] = {0};
  float x = 0;
  int ret = validator(expression, res);
  ck_assert_int_eq(ret, 0);
  double result = pol_notation(res, x);
  ck_assert_double_eq_tol(result, 120249.654684, 1e-7);
}
END_TEST

START_TEST(case_7) {
  char expression[255] = "122,1 * 877,9";
  char res[255] = {0};
  float x = 0;
  int ret = validator(expression, res);
  ck_assert_int_eq(ret, 0);
  double result = pol_notation(res, x);
  ck_assert_double_eq_tol(result, 107191.59, 1e-7);
}
END_TEST

START_TEST(case_8) {
  char expression[255] = "-1,9 * (-777,1)";
  char res[255] = {0};
  float x = 0;
  int ret = validator(expression, res);
  ck_assert_int_eq(ret, 0);
  double result = pol_notation(res, x);
  ck_assert_double_eq_tol(result, 1476.49, 1e-7);
}
END_TEST

START_TEST(case_10) {
  char expression[255] = "1                        +                       0,9";
  char res[255] = {0};
  float x = 0;
  int ret = validator(expression, res);
  ck_assert_int_eq(ret, 0);
  double result = pol_notation(res, x);
  ck_assert_double_eq_tol(result, 1.9, 1e-7);
}
END_TEST

START_TEST(case_11) {
  char expression[255] = "10 mod 3";
  char res[255] = {0};
  float x = 0;
  int ret = validator(expression, res);
  ck_assert_int_eq(ret, 0);
  double result = pol_notation(res, x);
  ck_assert_double_eq_tol(result, 1, 1e-7);
}
END_TEST

START_TEST(case_12) {
  char expression[255] = "25 / 5";
  char res[255] = {0};
  float x = 0;
  int ret = validator(expression, res);
  ck_assert_int_eq(ret, 0);
  double result = pol_notation(res, x);
  ck_assert_double_eq_tol(result, 5, 1e-7);
}
END_TEST

START_TEST(case_13) {
  char expression[255] = "2^9";
  char res[255] = {0};
  float x = 0;
  int ret = validator(expression, res);
  ck_assert_int_eq(ret, 0);
  double result = pol_notation(res, x);
  ck_assert_double_eq_tol(result, 512, 1e-7);
}
END_TEST

START_TEST(case_14) {
  char expression[255] = "cos(30)";
  char res[255] = {0};
  float x = 0;
  int ret = validator(expression, res);
  ck_assert_int_eq(ret, 0);
  double result = pol_notation(res, x);
  ck_assert_double_eq_tol(result, 0.1542514, 1e-7);
}
END_TEST

START_TEST(case_15) {
  char expression[255] = "cos(30)";
  char res[255] = {0};
  float x = 0;
  int ret = validator(expression, res);
  ck_assert_int_eq(ret, 0);
  double result = pol_notation(res, x);
  ck_assert_double_eq_tol(result, 0.1542514, 1e-7);
}
END_TEST

START_TEST(case_16) {
  char expression[255] = "sin(45)";
  char res[255] = {0};
  float x = 0;
  int ret = validator(expression, res);
  ck_assert_int_eq(ret, 0);
  double result = pol_notation(res, x);
  ck_assert_double_eq_tol(result, 0.8509035, 1e-7);
}
END_TEST

START_TEST(case_17) {
  char expression[255] = "tan(90)";
  char res[255] = {0};
  float x = 0;
  int ret = validator(expression, res);
  ck_assert_int_eq(ret, 0);
  double result = pol_notation(res, x);
  ck_assert_double_eq_tol(result, -1.9952004, 1e-7);
}
END_TEST

START_TEST(case_18) {
  char expression[255] = "acos(-0,3)";
  char res[255] = {0};
  float x = 0;
  int ret = validator(expression, res);
  ck_assert_int_eq(ret, 0);
  double result = pol_notation(res, x);
  ck_assert_double_eq_tol(result, 1.8754889, 1e-7);
}
END_TEST

START_TEST(case_19) {
  char expression[255] = "asin(0,5)";
  char res[255] = {0};
  float x = 0;
  int ret = validator(expression, res);
  ck_assert_int_eq(ret, 0);
  double result = pol_notation(res, x);
  ck_assert_double_eq_tol(result, 0.5235988, 1e-7);
}
END_TEST

START_TEST(case_20) {
  char expression[255] = "atan(1)";
  char res[255] = {0};
  float x = 0;
  int ret = validator(expression, res);
  ck_assert_int_eq(ret, 0);
  double result = pol_notation(res, x);
  ck_assert_double_eq_tol(result, 0.7853981, 1e-7);
}
END_TEST

START_TEST(case_21) {
  char expression[255] = "sqrt(9)";
  char res[255] = {0};
  float x = 0;
  int ret = validator(expression, res);
  ck_assert_int_eq(ret, 0);
  double result = pol_notation(res, x);
  ck_assert_double_eq_tol(result, 3, 1e-7);
}
END_TEST

START_TEST(case_22) {
  char expression[255] = "ln(99)";
  char res[255] = {0};
  float x = 0;
  int ret = validator(expression, res);
  ck_assert_int_eq(ret, 0);
  double result = pol_notation(res, x);
  ck_assert_double_eq_tol(result, 4.5951198, 1e-7);
}
END_TEST

START_TEST(case_23) {
  char expression[255] = "log(100)";
  char res[255] = {0};
  float x = 0;
  int ret = validator(expression, res);
  ck_assert_int_eq(ret, 0);
  double result = pol_notation(res, x);
  ck_assert_double_eq_tol(result, 2, 1e-7);
}
END_TEST

START_TEST(case_24) {
  char expression[255] =
      "(-0,5 - 0,375) / 1/8 - (-9,125 * (-0,21)) + (345000125 - 315752568) / "
      "(-458,3258)";
  char res[255] = {0};
  float x = 0;
  int ret = validator(expression, res);
  ck_assert_int_eq(ret, 0);
  double result = pol_notation(res, x);
  ck_assert_double_eq_tol(result, -63815.9261298, 1e-7);
}
END_TEST

START_TEST(case_25) {
  char expression[255] = "(17*1/5*0,125-(2*32/45-1/7/60))*(11/40/4*7/12+2,64)";
  char res[255] = {0};
  float x = 0;
  int ret = validator(expression, res);
  ck_assert_int_eq(ret, 0);
  double result = pol_notation(res, x);
  ck_assert_double_eq_tol(result, -2.66627823247, 1e-7);
}
END_TEST

START_TEST(case_26) {
  char expression[255] = "log(2) + (-1/2) * log(8) - ln(4 * sqrt(8))";
  char res[255] = {0};
  float x = 0;
  int ret = validator(expression, res);
  ck_assert_int_eq(ret, 0);
  double result = pol_notation(res, x);
  ck_assert_double_eq_tol(result, -2.57653012979, 1e-7);
}
END_TEST
START_TEST(case_27) {
  char expression[255] =
      "(cos(70)+cos(50))*(cos(310)+cos(290))-(sin(-40)+sin(-60))";
  char res[255] = {0};
  float x = 0;
  int ret = validator(expression, res);
  ck_assert_int_eq(ret, 0);
  double result = pol_notation(res, x);
  ck_assert_double_eq_tol(result, 0.49956901475, 1e-7);
}

START_TEST(case_28) {
  char expression[255] = "sin(cos(ln(sqrt(4))))";
  char res[255] = {0};
  float x = 0;
  int ret = validator(expression, res);
  ck_assert_int_eq(ret, 0);
  double result = pol_notation(res, x);
  ck_assert_double_eq_tol(result, 0.69558863622, 1e-7);
}
END_TEST

START_TEST(case_29) {
  char expression[255] = "-1,0/(-3,0)";
  char res[255] = {0};
  float x = 0;
  int ret = validator(expression, res);
  ck_assert_int_eq(ret, 0);
  double result = pol_notation(res, x);
  ck_assert_double_eq_tol(result, 0.33333333, 1e-7);
}
END_TEST

START_TEST(case_30) {
  char expression[255] =
      "tan(-85)*tan(15)+asin(0,8)-acos(1)/"
      "atan(0,5)+acos(-0,3)+asin(-0,7)*atan(-0,5)";
  char res[255] = {0};
  float x = 0;
  int ret = validator(expression, res);
  ck_assert_int_eq(ret, 0);
  double result = pol_notation(res, x);
  ck_assert_double_eq_tol(result, 3.31540708, 1e-7);
}
END_TEST

START_TEST(case_31) {
  char expression[255] = "(2^8 + 2^(-5))*(sqrt(144)/(-2))";
  char res[255] = {0};
  float x = 0;
  int ret = validator(expression, res);
  ck_assert_int_eq(ret, 0);
  double result = pol_notation(res, x);
  ck_assert_double_eq_tol(result, -1536.1875, 1e-7);
}
END_TEST

START_TEST(case_32) {
  char expression[255] = "(x^2+x^3+x^4+x^5+x^6+x^7+x^8+x^9)*5/(sqrt(900))";
  double x = 2;
  char res[255] = {0};
  int ret = validator(expression, res);
  ck_assert_int_eq(ret, 0);
  double result = pol_notation(res, x);
  ck_assert_double_eq_tol(result, 170.0, 1e-7);
}
END_TEST

START_TEST(case_33) {
  char expression[255] = "(-x-(-x))*x-(x)/x+1";
  double x = 5;
  char res[255] = {0};
  int ret = validator(expression, res);
  ck_assert_int_eq(ret, 0);
  double result = pol_notation(res, x);
  ck_assert_double_eq_tol(result, 0, 1e-7);
}
END_TEST

START_TEST(case_34) {
  char expression[255] = "sin(x)^2+cos(x)^2";
  double x = 1;
  char res[255] = {0};
  int ret = validator(expression, res);
  ck_assert_int_eq(ret, 0);
  double result = pol_notation(res, x);
  ck_assert_double_eq_tol(result, 1.0, 1e-7);
}
END_TEST

START_TEST(case_35) {
  char expression[255] = "5";
  double x = 1;
  char res[255] = {0};
  int ret = validator(expression, res);
  ck_assert_int_eq(ret, 0);
  double result = pol_notation(res, x);
  ck_assert_double_eq_tol(result, 5.0, 1e-7);
}
END_TEST

START_TEST(case_36) {
  char expression[255] = "1,5+2,0";
  char res[255] = {0};
  int ret = validator(expression, res);
  ck_assert_int_eq(ret, 0);
  double result = pol_notation(res, 0);
  ck_assert_double_eq_tol(result, 3.5, 1e-7);
}
END_TEST

START_TEST(case_extra_parenthesis) {
  char expression[255] = "(sin(x)^2+cos(x)^2)";
  char res[255] = {0};
  int ret = validator(expression, res);
  ck_assert_int_eq(ret, 0);
  double result = pol_notation(res, 0);
  ck_assert_double_eq_tol(result, 1, 1e-7);
}
END_TEST

/* check in mac i need add  empty staples*/
START_TEST(case_empty_parenthesis_1) {
  char expression[255] = "()";
  char res[255] = {0};
  int ret = validator(expression, res);
  ck_assert_int_eq(ret, 0);
}
END_TEST

START_TEST(case_empty_parenthesis_2) {
  char expression[255] = "sin()";
  char res[255] = {0};
  int ret = validator(expression, res);
  ck_assert_int_eq(ret, 0);
}
END_TEST

/* check double dot in one */
START_TEST(case_incorrect_number_1) {
  char expression[255] = "2,2324,243+5";
  char res[255] = {0};
  int ret = validator(expression, res);
  ck_assert_int_eq(ret, 17);
}
END_TEST

START_TEST(case_incorrect_number_2) {
  char expression[255] = "53435,,345-2";
  char res[255] = {0};
  int ret = validator(expression, res);
  ck_assert_int_eq(ret, 17);
}
END_TEST

START_TEST(case_incorrect_number_3) {
  char expression[255] = ",-2";
  char res[255] = {0};
  int ret = validator(expression, res);

  ck_assert_int_eq(ret, 17);
}
END_TEST

START_TEST(case_incorrect_number_4) {
  char expression[255] = "-6*-8";
  char res[255] = {0};
  int ret = validator(expression, res);
  ck_assert_int_eq(ret, 14);
}
END_TEST

START_TEST(case_incorrect_function_1) {
  char expression[255] = "sim(1)";
  char res[255] = {0};
  int ret = validator(expression, res);
  ck_assert_int_eq(ret, 6);
}
END_TEST

START_TEST(case_incorrect_function_2) {
  char expression[255] = "sin(x)^2+cosx)^2)";
  char res[255] = {0};
  int ret = validator(expression, res);
  ck_assert_int_eq(ret, 5);
}
END_TEST

START_TEST(case_incorrect_function_3) {
  char expression[255] = "sin(X)^2+cos*X)^2)";
  char res[255] = {0};
  int ret = validator(expression, res);
  ck_assert_int_eq(ret, 5);
}
END_TEST

START_TEST(case_incorrect_function_4) {
  char expression[255] = "sin+X^2+cos(X)^2)";
  char res[255] = {0};
  int ret = validator(expression, res);
  ck_assert_int_eq(ret, 6);
}
END_TEST

START_TEST(case_incorrect_function_5) {
  char expression[255] = "ton(X)^2+cos(X)^2)";
  char res[255] = {0};
  int ret = validator(expression, res);
  ck_assert_int_eq(ret, 11);
}
END_TEST

START_TEST(case_incorrect_function_6) {
  char expression[255] = "acos(X)^2+aspos(X)^2)";
  char res[255] = {0};
  int ret = validator(expression, res);
  ck_assert_int_eq(ret, 8);
}
END_TEST

START_TEST(case_incorrect_function_7) {
  char expression[255] = "asin-X)^2+cos(X)^2)";
  char res[255] = {0};
  int ret = validator(expression, res);
  ck_assert_int_eq(ret, 8);
}
END_TEST

START_TEST(case_incorrect_function_8) {
  char expression[255] = "sqrt(*X)^2+cos(X)^2)";
  char res[255] = {0};
  int ret = validator(expression, res);
  ck_assert_int_eq(ret, 16);
}
END_TEST

START_TEST(case_incorrect_function_9) {
  char expression[255] = "10 mod )";
  char res[255] = {0};
  int ret = validator(expression, res);
  ck_assert_int_eq(ret, 16);
}
END_TEST

START_TEST(case_incorrect_function_10) {
  char expression[255] = "tan(1) *+ 2";
  char res[255] = {0};
  int ret = validator(expression, res);
  ck_assert_int_eq(ret, 14);
}
END_TEST

START_TEST(case_incorrect_function_11) {
  char expression[255] = "atan(1) ^/ 2";
  char res[255] = {0};
  int ret = validator(expression, res);
  ck_assert_int_eq(ret, 14);
}
END_TEST

START_TEST(case_incorrect_function_12) {
  char expression[255] = "log(10+)";
  char res[255] = {0};
  int ret = validator(expression, res);
  ck_assert_int_eq(ret, 16);
}
END_TEST

START_TEST(case_incorrect_function_13) {
  char expression[255] = "log(X/)";
  char res[255] = {0};
  int ret = validator(expression, res);
  ck_assert_int_eq(ret, 16);
}
END_TEST

START_TEST(case_incorrect_function_14) {
  char expression[255] = "4x*2)";
  char res[255] = {0};
  int ret = validator(expression, res);
  ck_assert_int_eq(ret, 16);
}
END_TEST

START_TEST(case_incorrect_function_15) {
  char expression[255] = "+";
  char res[255] = {0};
  int ret = validator(expression, res);
  ck_assert_int_eq(ret, 14);
}
END_TEST

START_TEST(case_incorrect_function_16) {
  char expression[255] = "hello";
  char res[255] = {0};
  int ret = validator(expression, res);
  ck_assert_int_eq(ret, 15);
}
END_TEST

START_TEST(credit_calc_annuity) {
  double result;
  double mounthPayment;
  double allPay;
  annuityLoan(150000, 84, 16, &result, &mounthPayment, &allPay);
  ck_assert_double_eq_tol(result, 2979.31, 1e-1);
  ck_assert_double_eq_tol(mounthPayment, 100262.04, 1e-1);
  ck_assert_double_eq_tol(allPay, 250262.04, 1e-1);
}
END_TEST

START_TEST(credit_calc_differ) {
  double result;
  double mounthPayment;
  double allPay;
  double summ = 150000;
  int time = 7 * 12;
  while (time > 0) {
    differentiatedCredit(&summ, time, 16, &result, &mounthPayment, &allPay);
    /* code */
    time--;
  }

  //   ck_assert_double_eq_tol(result_credit.monthlyPaymentFrst, 3785.71, 1e-1);
  //   ck_assert_double_eq_tol(result_credit.monthlyPaymentLst, 1809.52, 1e-1);
  ck_assert_double_eq_tol(mounthPayment, 85000.00, 500);
  ck_assert_double_eq_tol(allPay, 235000.00, 500);
}
END_TEST

Suite *smartcalc_test() {
  Suite *s = suite_create("Calculator tests");
  TCase *tc_1 = tcase_create("calc tests");

  suite_add_tcase(s, tc_1);
  tcase_add_test(tc_1, case_1);
  tcase_add_test(tc_1, case_2);
  tcase_add_test(tc_1, case_3);
  tcase_add_test(tc_1, case_4);
  tcase_add_test(tc_1, case_5);
  tcase_add_test(tc_1, case_6);
  tcase_add_test(tc_1, case_7);
  tcase_add_test(tc_1, case_8);
  tcase_add_test(tc_1, case_10);
  tcase_add_test(tc_1, case_11);
  tcase_add_test(tc_1, case_12);
  tcase_add_test(tc_1, case_13);
  tcase_add_test(tc_1, case_14);
  tcase_add_test(tc_1, case_15);
  tcase_add_test(tc_1, case_16);
  tcase_add_test(tc_1, case_17);
  tcase_add_test(tc_1, case_18);
  tcase_add_test(tc_1, case_19);
  tcase_add_test(tc_1, case_20);
  tcase_add_test(tc_1, case_21);
  tcase_add_test(tc_1, case_22);
  tcase_add_test(tc_1, case_23);
  tcase_add_test(tc_1, case_24);
  tcase_add_test(tc_1, case_25);
  tcase_add_test(tc_1, case_26);
  tcase_add_test(tc_1, case_27);
  tcase_add_test(tc_1, case_28);
  tcase_add_test(tc_1, case_29);
  tcase_add_test(tc_1, case_30);
  tcase_add_test(tc_1, case_31);
  tcase_add_test(tc_1, case_32);
  tcase_add_test(tc_1, case_33);
  tcase_add_test(tc_1, case_34);
  tcase_add_test(tc_1, case_35);
  tcase_add_test(tc_1, case_36);
  tcase_add_test(tc_1, case_extra_parenthesis);
  tcase_add_test(tc_1, case_empty_parenthesis_1);
  tcase_add_test(tc_1, case_empty_parenthesis_2);
  tcase_add_test(tc_1, case_incorrect_number_1);
  tcase_add_test(tc_1, case_incorrect_number_2);
  tcase_add_test(tc_1, case_incorrect_number_3);
  tcase_add_test(tc_1, case_incorrect_number_4);
  tcase_add_test(tc_1, case_incorrect_function_1);
  tcase_add_test(tc_1, case_incorrect_function_2);
  tcase_add_test(tc_1, case_incorrect_function_3);
  tcase_add_test(tc_1, case_incorrect_function_4);
  tcase_add_test(tc_1, case_incorrect_function_5);
  tcase_add_test(tc_1, case_incorrect_function_6);
  tcase_add_test(tc_1, case_incorrect_function_7);
  tcase_add_test(tc_1, case_incorrect_function_8);
  tcase_add_test(tc_1, case_incorrect_function_9);
  tcase_add_test(tc_1, case_incorrect_function_10);
  tcase_add_test(tc_1, case_incorrect_function_11);
  tcase_add_test(tc_1, case_incorrect_function_12);
  tcase_add_test(tc_1, case_incorrect_function_13);
  tcase_add_test(tc_1, case_incorrect_function_14);
  tcase_add_test(tc_1, case_incorrect_function_15);
  tcase_add_test(tc_1, case_incorrect_function_16);
  tcase_add_test(tc_1, credit_calc_annuity);
  tcase_add_test(tc_1, credit_calc_differ);
  return s;
}

int main(void) {
  int nf = 0;
  int result = 0;
  Suite *s = smartcalc_test();

  SRunner *sr1 = srunner_create(s);

  srunner_run_all(sr1, CK_NORMAL);  // CK_VERBOSE
  nf += srunner_ntests_failed(sr1);
  srunner_free(sr1);

  if (nf == 0) {
    result = 0;
  } else {
    result = 1;
  }

  return result;
}