#include <stdio.h>

#include "s21_calc.h"

void pushChar(symbolicStack** front, dictionary x) {  // положить новый элемент
  symbolicStack* buf = (symbolicStack*)malloc(sizeof(symbolicStack));
  if (buf) {  // проверка malloc
    buf->next = *front;
    buf->symbol = x.symbol;
    buf->prioritet = x.prioritet;
    *front = buf;
  }
}

void pushDouble(stack** front, double x) {  // положить новый элемент

  stack* buf = (stack*)malloc(sizeof(stack));
  if (buf) {  // проверка malloc
    buf->next = *front;
    buf->value = x;
    *front = buf;
  } else {
    (*front)->value = x;
  }
}

int popChar(symbolicStack** front) {  // возвращает удаляемое значение
  symbolicStack* buf = NULL;
  int val = 0;
  if (front != NULL) {
    buf = (*front);
    val = (*front)->symbol;
    (*front) = (*front)->next;
    free(buf);
  }
  return val;
}

double popDouble(stack** front) {  // возвращает удаляемое значение
  stack* buf = NULL;
  double val = 0;
  if (front != NULL) {
    buf = (*front);
    val = (*front)->value;
    (*front) = (*front)->next;
    free(buf);
  }
  return val;
}
