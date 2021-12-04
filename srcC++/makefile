all: clean GobbletGobblers_v2

GobbletGobblers_v2: board.o logic.o interfaceConsole.o mainGobbletGobblers.o
	g++ board.o logic.o interfaceConsole.o mainGobbletGobblers.o -o GobbletGobblers_v2

board.o : logic/board.cpp 
	g++ -o board.o -c logic/board.cpp

logic.o : logic/logic.cpp
	g++ -o logic.o -c logic/logic.cpp

interfaceConsole.o : interface/interfaceConsole.cpp
	g++ -o interfaceConsole.o -c interface/interfaceConsole.cpp

mainGobbletGobblers.o : mainGobbletGobblers.cpp 
	g++ -o mainGobbletGobblers.o -c mainGobbletGobblers.cpp

clean: 
	rm -f *.o GobbletGobblers_v2