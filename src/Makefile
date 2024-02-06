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
	$(CC) $(CFLAGS) s21_math.c -c
	ar rcs s21_math.a *.o
	
test: clean s21_math.a
	$(CC) $(CFLAGS) tests/*.c s21_math.a $(CHECKFLAGS) -o s21_math
	./s21_math

gcov_report: clean s21_math.a
	$(CC) $(CFALGS) tests/*.c s21_math.c $(CHECKFLAGS) -fprofile-arcs -ftest-coverage -lgcov -o s21_math
	./s21_math
	lcov -t "./s21_math" -o report.info --no-external -c -d .
	genhtml -o report report.info
	open ./report/index.html

clang:
	clang-format -n -style=google tests/*.c tests/*.h *.h *.c

clangi:
	clang-format -i -style=google tests/*.c tests/*.h *.h *.c

valgrind: clean s21_math.a
	$(CC) $(CFLAGS) tests/*.c s21_math.a $(CHECKFLAGS) -o s21_math
	valgrind --tool=memcheck --leak-check=yes -s ./s21_math

clean:
	rm -rf s21_math *.a *.o a.out *.gcno *.gcda report report.info
