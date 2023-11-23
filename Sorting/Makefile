CFLAGS   = -Wall -Werror -O2 -std=c++11
CXXFLAGS = -Wall -Werror -O2
CC = gcc
CXX = g++


make:
	$(CXX) $(CFLAGS) qs.cc 
	./a.out

run_tests: date_new.o refrigerator.o fooditem.o oldandurgent itemcounts listbycat findall
	$(CC) $(CFLAGS) _TEST/TEST_cases.cc $(OBJECTS) -o _TEST/run_tests && ./_TEST/run_tests
run_qs: 
	$(CXX) $(CFLAGS) qs.cc
	./a.out