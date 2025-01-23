move_check: move-check.o move.o
	g++ -std=c++17 -Wall -Wextra -Werror -Wno-unused-parameter -o move_check move-check.o move.o

move_check.o: move-check.cpp 
	g++ -std=c++17 -Wall -Wextra -Werror -Wno-unused-parameter -c move-check.cpp

move.o: Move.cpp Move.h Errors.h
	g++ -std=c++17 -Wall -Wextra -Werror -Wno-unused-parameter -c Move.cpp

clean:
	rm -f *.o move_check