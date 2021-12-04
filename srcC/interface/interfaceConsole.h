#ifndef INTERCONSOLE_H_INCLUDED
#define INTERCONSOLE_H_INCLUDED
#include <stdio.h>
#include "../board.h"

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_RESET "\x1b[0m"

/**
 *  @brief Prints a white board. 
 * 
 *  Not used. 
 */
void printWhiteBoard();

/**
 *  @brief Prints the corresponding piece. 
 * 
 *  @param size, size of the piece to print. 
 *  @param player, player of the piece to print. 
 */
void printPiece(size piece, player current_player);

/**
 *  @brief Prints the existing pieces in the houses of each player
 * 
 *  @param board
 */
void printHouses(board game);

/**
 *  @brief Prints current board of the game. 
 * 
 *  @param board
 */
void printGameBoard(board game);

#endif /* INTERCONSOLE_H_INCLUDED */