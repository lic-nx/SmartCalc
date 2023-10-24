# мое
.PHONY: all build static install uninstall rebuild dist dvi test gcov_report clean

OS :=$(shell uname -s)
NAME :=$(shell whoami)
GC=gcc
CFLAGS=-std=c11 -Wall -Wextra -Werror -g
TEST=smart_calc_test
SPEC=special
GCOV=--coverage
SANI=-fsanitize=address -g


ifeq ($(OS), Darwin)
	FLAGS_PLATFORM =-lcheck
else
	FLAGS_PLATFORM =-lcheck -lsubunit -lrt -lm -lpthread -g
endif

all : install


install: clean s21_calc.a
ifeq ("", "$(wildcard Build)")
	mkdir Build
else
	rm -rf Build/*
endif
	cd calc/ && qmake && make &> /dev/null && make clean &> /dev/null &&  cd ../ && mv calc/calk.app Build
	make clean
	
clean :
	rm -rf *.{a,o,dSYM,out,g*} */*.{a,o,dSYM,out,g*} */*/*.{a,o,dSYM,out,g*} report test.info gcov f test main Dist_SmartCalc valgrind.txt

# библиотека для теста
s21_calc.a : calc/stack.c calc/s21_calc.c calc/credit.c calc/validator.c #libs/list_lib.c libs/calc.c
	$(GC) $(CFLAGS) -g -c calc/validator.c calc/stack.c calc/s21_calc.c calc/credit.c
#libs/list_lib.c libs/calc.c 
	ar rc s21_calc.a *.o 
	ranlib s21_calc.a
# mv s21_calc.a calc

uninstall: 
	rm -rf Build

dist: install
ifeq ("", "$(wildcard Dist_SmartCalc)")
	rm -rf Dist_SmartCalc/
endif
	make install &> /dev/null
	mkdir Dist_SmartCalc/
	mkdir Dist_SmartCalc/src
	mv ./Build/calk.app Dist_SmartCalc/src/
	tar cvzf Dist_SmartCalc.tgz Dist_SmartCalc/ &>/dev/null
	rm -rf Dist_SmartCalc/
	rmdir Build
undist:
	rm -rf *.tgz

dvi: 
	open README.txt
	
test : clean s21_calc.a $(TEST).o
	$(GC) $(CFLAGS) $(TEST).o -l check -L. s21_calc.a $(FLAGS_PLATFORM) -o test
	./test 


$(TEST).o : $(TEST).c
	$(GC) $(CFLAGS) -c $(TEST).c -o $(TEST).o



gcov_report : clean lcov $(TEST).o gs21_calc.a
	$(GC) $(CFLAGS) $(GCOV) $(TEST).o -l check -L. s21_calc.a $(FLAGS_PLATFORM) -o gcov
	./gcov gs21_calc.a 
	gcov gs21_calc.a
# ~/goinfre/homebrew/bin/
	lcov -t "test" -o test.info -c -d . 
	genhtml -o report test.info 
	open report/index.html 

# библиотека для отчета
gs21_calc.a : calc/validator.c calc/stack.c calc/s21_calc.c calc/credit.c
	$(GC) $(GCOV) -g -c calc/validator.c calc/stack.c calc/s21_calc.c calc/credit.c
	ar rc s21_calc.a *.o 
	ranlib s21_calc.a

# проверки lcov и brew
lcov: lcov_install
ifeq ("", "$(wildcard ~/goinfre/homebrew/bin/lcov)")
	make lcov_install
endif

lcov_install :  brew
	brew install lcov

brew:
ifeq ("", "$(wildcard ~/goinfre/homebrew)")
	git clone https://github.com/Homebrew/brew ~/goinfre/homebrew
#   curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
endif

valgrind: clean test
# brew tap LouisBrunner/valgrind
# brew install --HEAD LouisBrunner/valgrind/valgrind
	CK_FORK=no valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all --verbose --log-file=valgrind.txt ./test

check: 
	cd calc && clang-format -style=Google -n *.h *.c *.cpp *.cc
