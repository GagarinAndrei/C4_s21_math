CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11

all: clean s21_math.a


s21_math.a:
	$(CC) $(CFLAGS) lib/*.c -c
	ar rc libs21_math.a *.o
	ranlib libs21_math.a
	
test: clean s21_math.a
	$(CC) $(CFLAGS) tests/*.c -L. -ls21_math -lcheck -o s21_math
	./s21_math

clean:
	rm -f *.o s21_math libs21_math.a
