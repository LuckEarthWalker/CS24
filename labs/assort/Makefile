CXXFLAGS = -g -std=c++17 -Wall -Wextra -Werror -Wno-unused-parameter
CXX      = g++

all: assort

assort: test.o list.o
	${CXX} ${CXXFLAGS} -o $@ $+

test.o: test.cpp List.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

list.o: List.cpp List.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

clean:
	rm -f assort *.o