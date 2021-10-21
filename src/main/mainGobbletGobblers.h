#ifndef MAINGG_H_INCLUDED
#define MAINGG_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>         /* pour system()*/
#include <unistd.h>         /* pour sleep()*/
#include "../board.h"
#include "../logicGame/logicGame.h"

//#include "../auxiliar/auxiliar.h"

/**
 * @brief Asks the user which game mode to play. 
 *
 *  1. Game mode: 2 players.
 *  2. To implement...
 *
 * @return 1 to play 2 players mode, 0 to exit the game.
 */
int menuPrincipal();

/**
 * @brief Launches the game depending on the result of menuPrincipal()
 *
 *  Returns a (standard) 0 for success.
 *
 * @return 0
 */
int main(int args, char **argv);

#endif /* MAINGG_H_INCLUDED */