#Флаги
GCC= gcc -c
GCCG= gcc
FLAGS= -Wall -Werror -Wextra -std=c11
LFLAGS = -Wall -Werror -Wextra -g -fsanitize=leak -fsanitize=address -fsanitize=undefined -fsanitize=unreachable -fno-sanitize-recover -fstack-protector -fanalyzer
GCOV_FLAGS= -fprofile-arcs -ftest-coverage -fPIC
ifeq ($(UNAME),Linux)
	LDFLAGS=-lcheck_pic -lsubunit -lm -lrt -lpthread
	OPEN_CM=xdg-open
endif
ifeq ($(UNAME),Darwin)
	LDFLAGS=-lcheck -lm
	OPEN_CM=open
endif

#файлы проекта
F_H= s21_math.h
F_C= functions/*.c 
#файлы тестов
FT_H= tests/s21_math_tests.h
FT_C= test.c 
FT_CH= tests/*.check
SOURCE_TESTS= -lcheck -o test # -pthread -lcheck_pic -pthread -lrt -lm -lsubunit  // флаги сообщающие путь к библиотеке check  убунту

#======================================== ALL =========================================================================
all: clean gcov_report

# ======================================= Компиляция тестов ===========================================================
test: clean s21_math.a make_tests
	${GCCG} ${FLAGS} ${SOURCE_TESTS} ${FT_C} s21_math.a ${LDFLAGS} 
	./test

make_tests:
	checkmk clean_mode=1 tests/*.check > test.c
	clang-format -i test.c

# ======================================= Вывод тестов в HTML отчет ===================================================

gcov_report: clean gs21_math.a make_tests
	${GCCG} ${FLAGS} ${FT_C} s21_math.a ${SOURCE_TESTS} ${LDFLAGS} ${GCOV_FLAGS}
	./test
	lcov -t "Math_tests" -o test_rez.info -c -d .
	genhtml -o report test_rez.info
	rm *.gcda *.gcno *.info
	open report/index.html

# ======================================= Тесты на утечки (которых в math нет) =============================================================
tests_valgrind: test
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=res_leak.txt ./test
	grep -e ERROR res_leak.txt
	rm -rf *.gcda
tests_valgrind_gcov: gcov_report
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=res_leak.txt ./test
	grep -e ERROR res_leak.txt
	rm -rf *.gcda

leaks: clean s21_math.a make_tests
	valgrind --tool=memcheck --leak-check=yes  ./a.out
	leaks -atExit -- ./test
	$(GCCG) $(LFLAGS) ${SOURCE_TESTS} tests/*.c  s21_math.a -o 1
	./1
# ======================================= Сборка библиотеки в файл s21_math.a =========================================
s21_math.a: clean
	${GCC} ${FLAGS} ${F_C}
	ar rc s21_math.a *.o
	ranlib s21_math.a
	make clean.o

gs21_math.a: clean
	${GCC} ${FLAGS} ${F_C} ${GCOV_FLAGS}
	ar rc s21_math.a *.o
	ranlib s21_math.a
	make clean.o

# ======================================= Работа со стилями в проекте =================================================
cppchecker:
	cppcheck ${F_C} ${F_H} ${FT_C} ${FT_H}

style:
	clang-format -n ${F_C} ${F_H}
	
style_red:
	clang-format -i ${F_C} ${F_H}

# ======================================= Clean =======================================================================
clean.o:
	rm -rf *.o
clean.a:
	rm -rf *.a
clean.gcno:
	rm -rf *.gcno
clean.gcda:
	rm -rf *.gcda
clean:
	rm -rf *.o *.out *.a
	rm -rf test test.c
	rm -rf *.gcno *.gcda *.gcov
	rm -rf *.txt *.html *.css
	rm -rf report
