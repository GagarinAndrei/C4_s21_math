CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11

ifeq ($(shell uname), Linux)
	CHECKFLAGS=-lcheck -lm -lpthread -lrt 
#-lsubunit
else
	CHECKFLAGS=-lcheck -lm -lpthread
endif

all: clean s21_math.a

s21_math.a:
	$(CC) $(CFLAGS) lib/*.c -c
	ar rc libs21_math.a *.o
	ranlib libs21_math.a
	
test: clean s21_math.a
	$(CC) $(CFLAGS) tests/*.c -L. -ls21_math $(CHECKFLAGS) -o s21_math
	./s21_math

gcov_report: clean s21_math.a
	$(CC) $(CFALGS) tests/*.c -L. -ls21_math $(CHECKFLAGS) -fprofile-arcs -ftest-coverage -lgcov -o s21_math
	./s21_math
	lcov -t "./s21_math" -o report.info --no-external -c -d .
	genhtml -o report report.info
	open ./report/index.html

clean:
	rm -rf s21_math *.a *.o a.out *.gcno *.gcda report report.info
