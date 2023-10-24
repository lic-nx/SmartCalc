#include "credit.h"

//&summ, time, procent, &monthly_payment, &overpayment, &total_payout

void annuityLoan(double creditSumm, int timeCredit, int percent, double *result,
                 double *mounthPayment, double *allPay) {
  double mpc = ((double)percent / 12) / 100;  // месячная процентная ставка
  double coef = (mpc * pow((1 + mpc), timeCredit)) /
                (pow((1 + mpc), timeCredit) - 1);  // коэф аннуиттета
  *result = creditSumm * coef;  // ежемесячный платеж
  *mounthPayment = timeCredit * *result - creditSumm;  // переплата
  *allPay = *mounthPayment + creditSumm;
  // ежемесечный платеж, переплата по кредиту, общая выплата
}

void differentiatedCredit(double *creditSumm, int timeCredit, int percent,
                          double *SumDifinMounth, double *procentSumm,
                          double *totalPayout) {
  float diffDolg =
      *creditSumm / timeCredit;  //сколько надо выплатить в месяц без процентов

  float summPro = *creditSumm * percent * (30 + timeCredit % 2) /
                  (365 * 100);  // проценты за один месяц
  *procentSumm += summPro;      // переплата
  *SumDifinMounth = summPro + diffDolg;  //итоговая выплата за месяц
  *totalPayout += *SumDifinMounth;  // сколько надо выплатить
  *creditSumm = *creditSumm - diffDolg;  // то сколько погасили
}
