#ifndef LOGIC_H
#define LOGIC_H

#include "board.h"
#include "../interface/interfaceConsole.h"

class Logic{
    private:

    public:
        Logic();
        int check_input(int min, int max, std::string question);
        void choix(Board &board, player current_player);
        //void check_turn(int choixTour, int type, int line, int column, int line_final, int column_final, int *valide, int current_player, Board board);
        int play1vs1();
};
#endif //LOGIC_H