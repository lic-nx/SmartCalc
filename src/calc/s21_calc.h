#ifndef S21_CALC_H_
#define S21_CALC_H_

#include <ctype.h>
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack {
  double value;
  struct stack* next;
} stack;

typedef struct dictionary {
  char symbol;
  int prioritet;
  /* data */
} dictionary;

typedef struct symbolicStack {
  char symbol;
  int prioritet;
  struct symbolicStack* next;
} symbolicStack;

int checker2(char x);

void pushChar(symbolicStack** front, dictionary x);
int checkChars(char i, char* str, int len);
void pushDouble(stack** front, double x);
int popChar(symbolicStack** front);
double popDouble(stack** front);
int add_number(char* str, int j, double* res);
void Chet(stack** numbers, symbolicStack** symbols, int* err);
dictionary RetPrior(char symb);
double pol_notation(char* str, float x);
int validator(char* str, char* ret);
int checker(char x);

#endif  // S21_CALC_H_
