.PHONY: directories clean

all: directories bin/ut_all

bin/ut_all: hw2_110590034.cpp Matrix.h Matrix.cpp
	g++ -std=c++11 hw2_110590034.cpp Matrix.cpp -o bin/ut_all -lgtest -lpthread

directories:
	mkdir -p bin

clean:
	rm -rf bin