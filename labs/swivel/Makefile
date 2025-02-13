CXX = g++
CXXFLAGS = -g -std=c++17 -Wall -Wextra -Werror -Wno-unused-parameter

all: swivel

swivel: test.o set.o node.o
	${CXX} ${CXXFLAGS} -o $@ $+

test.o:	test.cpp Set.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

set.o: Set.cpp Set.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

node.o: Node.cpp Node.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

clean:
	rm -f swivel *.o 