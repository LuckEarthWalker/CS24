CXX = g++
CXXFLAGS = -g -std=c++17 -Wall -Wextra -Werror -Wno-unused-parameter

all: typo

test: test.o heap.o
	${CXX} ${CXXFLAGS} -o $@ $+

test.o: test.cpp Heap.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

typo: main.o wordlist.o point.o heap.o
	${CXX} ${CXXFLAGS} -o $@ $+

main.o: main.cpp WordList.h Point.h Heap.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

wordlist.o: WordList.cpp WordList.h Heap.h Point.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

point.o: Point.cpp Point.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

heap.o: Heap.cpp Heap.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

clean:
	rm -f typo test *.o