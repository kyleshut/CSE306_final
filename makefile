OBJECTS = kitchen.o dummy.o anotherdummy.o

# OS identification from: https://stackoverflow.com/questions/714100/os-detecting-makefile
OS := $(shell uname -s)

ifeq ($(OS), Darwin) 
  CUNIT_PATH_PREFIX = /usr/local/Cellar/cunit/2.1-3/
  CUNIT_DIRECTORY = cunit
endif
ifeq ($(OS), Linux) 
  CUNIT_PATH_PREFIX = /util/CUnit/
  CUNIT_DIRECTORY = CUnit/
endif

CC = gcc
FLAGS = -g -O0 -c -Wall -fprofile-arcs -ftest-coverage 
PERFFLAGS = -pg -fprofile-arcs -ftest-coverage
CFLAGS = -L $(CUNIT_PATH_PREFIX)lib -I $(CUNIT_PATH_PREFIX)include/$(CUNIT_DIRECTORY) 
SRC = kitchen.c
GEX = kitchen-gprof

kitchen.o: kitchen.c
	$(CC) $(FLAGS) kitchen.c

dummy.o: dummy.c
	$(CC) $(FLAGS) dummy.c

anotherdummy.o: anotherdummy.c
	$(CC) $(FLAGS) anotherdummy.c

tests: $(OBJECTS) tests.c
	$(CC) -g -O0 -Wall -fprofile-arcs -ftest-coverage -L $(CUNIT_PATH_PREFIX)lib  -I $(CUNIT_PATH_PREFIX)include/$(CUNIT_DIRECTORY) $(OBJECTS) tests.c -o tests -lcunit -lgcov 

clean:
	rm -rf *~ *.o *.dSYM a.out runner tests *.xml *.gc??

c-exec: kitchen.o dummy.o anotherdummy.o
	gcc -g -O0 -Wall $(PERFFLAGS) $(CFLAGS) -o $(GEX) $(SRC) tests.c  -lcunit

.PHONY: andRunPerformance
andRunPerformance:
	make clean
	make c-exec
	./$(GEX)
	gprof -b ./$(GEX) gmon.out > analyze.txt 
	gcov $(SRC) 
	@echo "Look at analyze.txt for gprof timing data"
	@echo "Look at $(SRC).gcov for gcov annotated source code with execution counts"
