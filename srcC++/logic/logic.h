#ifndef LOGIC_H
#define LOGIC_H

#include <vector>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

#include "board.h"
#include "../interface/interfaceConsole.h"

enum bot_e {RANDOM, ONELAYER, TWOLAYER, INVINCIBOT};
typedef enum bot_e bot;

class Logic{
    private:

    public:
        Logic();
        int check_input(int min, int max, std::string question);
        void make_move(Board &board, player current_player);
        void simulate_move(Board &board, player current_player, bot current_bot);
        //void check_turn(int choix, int type, int line, int column, int line_final, int column_final, int *valide, int current_player, Board board);
        int play1vs1();
        bot askBotType();
        int play1vsbot();
};
#endif //LOGIC_H