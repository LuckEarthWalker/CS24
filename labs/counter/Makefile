CXX = g++
CXXFLAGS = -g -std=c++17 -Wall -Wextra -Werror -Wno-unused-parameter -O3

all: counter

counter: main.o counter.o list.o index.o iterator.o
	${CXX} ${CXXFLAGS} -o $@ $+

main.o: main.cpp Counter.h
	${CXX} ${CXXFLAGS} -c -o $@ $<


char: char.o counter.o list.o index.o iterator.o
	${CXX} ${CXXFLAGS} -o $@ $+

char.o: char-count.cpp Counter.h
	${CXX} ${CXXFLAGS} -c -o $@ $<


word: word.o counter.o list.o index.o iterator.o
	${CXX} ${CXXFLAGS} -o $@ $+

word.o: word-count.cpp Counter.h
	${CXX} ${CXXFLAGS} -c -o $@ $<


counter.o: Counter.cpp Counter.h List.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

list.o: List.cpp List.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

index.o: Index.cpp Index.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

iterator.o: Iterator.cpp Counter.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

clean: 
	rm -f counter char word *.o