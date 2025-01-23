move_check: move-check.o move.o
	g++ -std=c++17 -Wall -Wextra -Werror -Wno-unused-parameter -o move_check move-check.o move.o

move_check.o: move-check.cpp 
	g++ -std=c++17 -Wall -Wextra -Werror -Wno-unused-parameter -c move-check.cpp

move.o: Move.cpp Move.h Errors.h
	g++ -std=c++17 -Wall -Wextra -Werror -Wno-unused-parameter -c Move.cpp

game_check: game-check.o move.o board.o
	g++ -std=c++17 -Wall -Wextra -Werror -Wno-unused-parameter -o game_check game-check.o move.o board.o

game-check.o: game-check.cpp Board.h Errors.h Move.h
	g++ -std=c++17 -Wall -Wextra -Werror -Wno-unused-parameter -c game-check.cpp

board.o: Board.cpp Board.h Errors.h
	g++ -std=c++17 -Wall -Wextra -Werror -Wno-unused-parameter -c Board.cpp

clean:
	rm -f *.o move_check game_check