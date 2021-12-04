all: clean GobbletGobblers_v1

GobbletGobblers_v1 : board.o interfaceConsole.o auxiliar.o logicGame.o mainGobbletGobblers.o
	gcc board.o interfaceConsole.o auxiliar.o logicGame.o mainGobbletGobblers.o -o GobbletGobblers_v1
	@echo ""

interfaceConsole.o: interface/interfaceConsole.c
	@echo "* Building project..."
	gcc -o interfaceConsole.o -c interface/interfaceConsole.c

auxiliar.o: auxiliar/auxiliar.c
	gcc -o auxiliar.o -c auxiliar/auxiliar.c

logicGame.o: logicGame/logicGame.c
	gcc -o logicGame.o -c logicGame/logicGame.c

mainGobbletGobblers.o: main/mainGobbletGobblers.c
	gcc -o mainGobbletGobblers.o -c main/mainGobbletGobblers.c

clean:
	@echo "* Cleaning project..."
	rm -f interfaceConsole.o auxiliar.o logicGame.o mainGobbletGobblers.o
	@echo ""
	