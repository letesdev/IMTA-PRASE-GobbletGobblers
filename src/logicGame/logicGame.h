#ifndef LOGICGAME_H_INCLUDED
#define LOGICGAME_H_INCLUDED

#include <stdio.h>
#include <stdlib.h> /* para system()*/
#include <unistd.h> /* para sleep()*/
#include "../board.h"
#include "../auxiliar/auxiliar.h"
#include "../interface/interfaceConsole.h"

/**
 *  @brief Asks the user what to do. Represents a turn. 
 * 
 *  The player can: 
 *      1. Put a new piece on the board, on an empty space or over a smaller piece.
 *      2. Move one of your pieces already on the board to an empty space or over a smaller piece.
 *
 *  After that choice done,
 *      1. If the player wants to put a new piece on the board, the game asks for the line, the 
 *      column and the size of the piece. 
 *      2. If the player wants to move a piece, the game asks for the line and the column of the existing
 *      piece and then asks for the final position of the piece (line and column). 
 *
 *  @param board, initialized when starting the game
 *  @param player, current player
 * 
 *  @return 1 to play 2 players mode, 0 to exit the game.
 */
void choix(board game, player current_player);


/**
 *  @brief Checks the choice of the user. 
 * 
 *  Not used. Checks are already performed in board.o, but will leave the function here
 *  for the next version of the game where board.c needs to be implemented. 
 *
 *  @param board, initialized when starting the game
 *  @param player, current player
 * 
 *  @return 1 to play 2 players mode, 0 to exit the game.
 */
void check_turn(int choixTour, int type, int line, int column, int line_final, int column_final, int *valide, int current_player, board game);

/**
 *  @brief 2 players game mode. 
 * 
 *  In turns, each player can either: 
 *      1. Put a new piece on the board, on an empty space or over a smaller piece.
 *      2. Move one of your pieces already on the board to an empty space or over a smaller piece.
 * 
 *  Wins the first player to get three pieces in a row. 
 *
 *  @param board, initialized when starting the game
 * 
 *  @return 1 to play 2 players mode, 0 to exit the game.
 */
int play1vs1(board game);

#endif /* AUXILIAR_H_INCLUDED */