#include "s21_calc.h"

#include <stdio.h>

// конвертируем строку в число после записываем его в res
// возвращает положение где нет уже числа
// подаем строку, символ начала числа, куда записать число
int add_number(char* str, int j, double* res) {
  // char regex_pattern[] = "[0-9,.]";  // регулярное выражение
  char strNum[50] = {0};
  int i = 0;
  while (isdigit(str[i + j]) || str[i + j] == '.') {
    strNum[i] = str[i + j];
    i++;
  }
  // printf("%s", strNum);
  setlocale(LC_NUMERIC, "en_US.utf8");
  *res = atof(strNum);
  return j + i;  // возвращаем то где заканчивается число
}

// Функция для вытаскивания знаков из стека и использовании на числах
void Chet(stack** numbers, symbolicStack** symbols, int* err) {
  double tmp = 0;

  if (symbols != NULL && numbers != NULL) {
    char timeVal = (*symbols)->symbol;
    // printf("timeVal= %c \n", timeVal);
    switch (timeVal) {
      case '+':
        tmp = popDouble(numbers) +
              (*numbers)
                  ->value;  // тип возвращаем последнее и предпоследнее число
        break;

      case '-':
        tmp = popDouble(numbers);
        tmp = (*numbers)->value -
              tmp;  // тип возвращаем последнее и предпоследнее число
        break;
      case '*':
        tmp = popDouble(numbers) * (*numbers)->value;
        // тип возвращаем последнее и предпоследнее число
        break;
      case '/':
        tmp = popDouble(numbers);
        if (tmp == 0) *err = 1;
        tmp = (double)(*numbers)->value / tmp;
        // тип возвращаем последнее и предпоследнее число
        break;
      case '^':
        tmp = popDouble(numbers);
        tmp = pow((double)(*numbers)->value, tmp);
        // тип возвращаем последнее и предпоследнее число
        break;
      case 'c':
        tmp = cos((double)(*numbers)->value);
        break;
      case 's':
        tmp = sin((double)(*numbers)->value);
        break;
      case 't':
        tmp = tan((double)(*numbers)->value);
        break;
      case 'C':
        tmp = acos((double)(*numbers)->value);
        break;
      case 'S':
        tmp = asin((double)(*numbers)->value);
        break;
      case 'T':
        tmp = atan((double)(*numbers)->value);
        break;
      case 'q':
        tmp = sqrt((*numbers)->value);  // число >0
        break;
      case 'm':
        tmp = popDouble(numbers);
        tmp = ((int)(*numbers)->value % (int)tmp);
        // тип возвращаем последнее и предпоследнее число
        break;
      case 'l':
        tmp = log((double)(*numbers)->value);
        break;
      case 'L':
        tmp = log10((double)(*numbers)->value);
        break;
    }
    popChar(symbols);  // удаляю использованный знак
    (*numbers)->value = tmp;
  }
}

dictionary RetPrior(char symb) {
  static const dictionary
      massDictionary[] = {{'+', 1},   {'-', 1}, {'*', 2}, {'/', 2}, {'^', 3},
                          {'c', 4},   {'s', 4}, {'t', 4}, {'C', 4}, {'S', 4},
                          {'T', 4},   {'q', 4}, {'m', 2}, {'l', 4}, {'L', 4},
                          {'(', 100}, {')', 0}};  // временное значение.
                                                  // разработчик выкатит
                                                  // обновление
  static const int dictionarySize =
      sizeof(massDictionary) / sizeof(massDictionary[0]);
  dictionary ret = {0, -1};
  for (int j = 0; j < dictionarySize; j++) {
    if (massDictionary[j].symbol == symb) ret = massDictionary[j];
  }
  return ret;
}

double pol_notation(char* str, float x) {
  //  double ret = 0;
  int err = 0;
  symbolicStack* symbols = {0};  // стек символов
  stack* numbers = {0};          // стек чисел
  // printf("\nstr = %s ", str);
  for (size_t i = 0; i < strlen(str) && err == 0; i++) {
    if (isdigit(str[i])) {  // вводить x
      double tmp = 0;
      i = add_number(str, i, &tmp);
      pushDouble(&numbers, tmp);
    } else if (str[i] == 'x') {
      pushDouble(&numbers, x);
    }
    const dictionary operator= RetPrior(str[i]);
    if (operator.symbol) {
      if (operator.symbol == ')') {
        while (symbols->symbol != '(') Chet(&numbers, &symbols, &err);
        popChar(&symbols);
      } else {
        while (symbols && symbols->symbol != '(' &&
               symbols->prioritet >= operator.prioritet) {
          Chet(&numbers, &symbols, &err);
        }
        pushChar(&symbols, operator);
      }
    }
  }
  while (symbols != NULL && err == 0) {
    Chet(&numbers, &symbols, &err);
  }
  double calc = numbers->value;
  free(numbers);
  free(symbols);
  return calc;
}

// void make() { printf("%lf ", StepByStepChecker("cos(180)")); }
