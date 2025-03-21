CXXFLAGS = -g -std=c++17 -Wall -Wextra -Werror -Wno-unused-parameter -O3 -pg -g
CXX      = g++

.PHONY: clean
all: bomber

bomber: bomber.o point.o map.o
	${CXX} $(CXXFLAGS) -o $@ $+

bomber.o: main.cpp Errors.h Map.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

point.o: Point.cpp Point.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

map.o: Map.cpp Map.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f *.o bomber