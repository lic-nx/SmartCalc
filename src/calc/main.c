#include "s21_calc.h"
// проверка на совпадение числа открывающих и закрывающих скобок
// переделка минуса на унарный
// проверка на введение точки вместо запятой
// проверка что перед точкой и после есть цифры

// int checker(char x) {
//   int err = 0;
//   if (strchr("-+/*^)(", x))
//   err = 2;  // если есть знак то возвращаем да
//   return err;
// }

int checker2(char x) {
  int err = 0;
  if (strchr("*/^m", x)) err = 13;  // если есть знак то возвращаем да

  return err;
}

int checkChars(char i, char* str, int len) {
  int err = 0;
  if (i >= len - 1 || checker2(str[i + 1]) || checker2(str[i - 1])) {
    err = 14;
  }
  return err;
}

int validator(char* str, char* ret) {
  // char *ret = calloc(strlen(str) + 4, sizeof(char));
  int staples = 0;
  int dots = 0;  //
  int err = 0;  // если нашли хоть одну ошибку пишем неверный ввод
  // int t = strlen(str);
  int j = 0;
  int len = strlen(str);
  if (str[0] == '-' && err == 0) {
    ret[j] = '0';  // проверяем унарный минус
    j++;
  }
  if (checker2(str[0])) {
    err = 7;
  }
  if (len == 0 || len >= 254) {
    err = 3;
  }
  for (int i = 0; i < (len) && err == 0; ++i) {
    ret[j] = str[i];
    // printf("now = %c \n", str[i]);
    // printf("stap1 = %d\n", staples);
    if (!isdigit(str[i]) && str[i] != '.' && str[i] != ',') {
      dots = 0;
    }
    switch (str[i]) {
      case '-':
        if (str[i - 1] > 0 && str[i - 1] == '(') {
          ret[j] = '0';
          j++;
          ret[j] = '-';
        }
        if (i >= len - 1 || checker2(str[i + 1])) {
          err = 1;
        }
        break;
      case '/':
        if (str[i + 1] == '0' && str[i + 2] != '.') {
          err = 4;
        }
        err = checkChars(i, str, len);
        break;
      case '+':
      case '*':
      case '^':
        err = checkChars(i, str, len);
        break;

      case '(':
        staples += 1;  // смотрим число скобок
        break;
      case ')':
        staples -= 1;  // следим чтоб все закрывалось
        break;
      case ',':
        ret[j] = '.';
        if (str[i - 1] < '0' || str[i - 1] > '9' || str[i + 1] < '0' ||
            str[i + 1] > '9' ||
            dots == 1)  // смотрим чтб перед точкой и после было число
          err = 17;
        dots = 1;
        break;
      case 'c':
        if (str[i + 1] == 'o' && str[i + 2] == 's' && str[i + 3] == '(')
          i += 2;
        else
          err = 5;
        break;

      case 's':
        if (str[i + 1] == 'i' && str[i + 2] == 'n' && str[i + 3] == '(') {
          i += 2;
        } else if (str[i + 1] == 'q' && str[i + 2] == 'r' &&
                   str[i + 3] == 't' && str[i + 4] == '(') {
          ret[j] = 'q';
          i += 3;
        } else {
          err = 6;
        }
        break;

      case 't':
        if (str[i + 1] == 'a' && str[i + 2] == 'n' && str[i + 3] == '(')
          i += 2;
        else
          err = 11;
        break;

      case 'a':
        if (str[i + 1] == 'c' && str[i + 2] == 'o' && str[i + 3] == 's' &&
            str[i + 4] == '(') {
          ret[j] = 'C';
        } else if (str[i + 1] == 's' && str[i + 2] == 'i' &&
                   str[i + 3] == 'n' && str[i + 4] == '(') {
          ret[j] = 'S';
        } else if (str[i + 1] == 't' && str[i + 2] == 'a' &&
                   str[i + 3] == 'n' && str[i + 4] == '(') {
          ret[j] = 'T';
        } else
          err = 8;
        i += 3;
        break;
      case 'm':
        if (str[i + 1] == 'o' && str[i + 2] == 'd') {
          ret[j] = 'm';
          i += 2;
        } else
          err = 10;
        if (i >= len - 1) {
          err = 12;
        }
        break;
      case 'l':
        if (str[i + 1] == 'n') {
          ret[j] = 'l';
          i += 1;
        } else if (str[i + 1] == 'o' && str[i + 2] == 'g') {
          ret[j] = 'L';
          i += 2;
        } else {
          err = 15;
        }
      default:
        break;
    }
    j++;
  }
  printf(" err tt = %d\n", err);
  if (staples != 0) err = 16;
  return err;
}

int main() {
  char src[255];
  printf("before validator = %s\n", src);
  int err = validator("2,2324,243+5", src);
  printf("after validator = %d\n", err);
  printf("after validator = %s\n", src);
  return 0;
}