#ifndef INTERCONSOLE_H
#define INTERCONSOLE_H

#include "../logic/board.h"

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_RESET "\x1b[0m"

class Terminal{
    private:
        
    public:
        // Constructeur par défaut
        Terminal();

        void printWhiteBoard();
        void printPiece(size piece, player current_player);
        void printHouses(Board &board);
        void printGameBoard(Board &board);
};

#endif /* INTERCONSOLE_H */