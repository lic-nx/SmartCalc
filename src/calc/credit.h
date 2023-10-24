#ifndef CREDIT_H_
#define CREDIT_H_

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void annuityLoan(double creditSumm, int timeCredit, int percent, double *result,
                 double *mounthPayment, double *allPay);
void differentiatedCredit(double *creditSumm, int timeCredit, int percent,
                          double *SumDifinMounth, double *procentSumm,
                          double *totalPayout);

#endif  // CREDIT_H_
