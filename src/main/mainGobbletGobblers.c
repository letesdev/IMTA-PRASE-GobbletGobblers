#include "mainGobbletGobblers.h"


/**
 * @file main_example.c
 * @brief a simple illustration of how to include and use board.h and board.o.
 */

int menuPrincipal(){
    int valor;

    printf("Bienvenu au jeu de Gobblet Gobblers.\n \
    Choisisez une option pour continuer, puis appuyez ENTER:\n \
    \t 1. Deux joueurs. \n \
    N'importe quel numéro pour sortir...\n \
    Option choisie: ");
    scanf("%d", &valor);
    
    return valor;
}

int main(int args, char **argv){
	int playerG = 0;
    board game = new_game();
    while (1){
        system("clear");            /* Clear Screen */
        switch (menuPrincipal()){
            case 1:                 /* Mode de jeu: deux joueurs */
                playerG = play1vs1(game);
                destroy_game(game);
                printf("Victoire du joueur #%d !!!\n", playerG);
                printf("Au revoir!\n");
                return 0;
            case 2:                 /* Mode de jeu: machine vs current_player */
                //printf("2");
                
                continue;
    /*        case '3':
                otrafuncion();
                continue; */
            /* Salida */
            case 0:
            default:
                /* Dejamos la consola como nos la encontramos */
                printf("Au revoir!\n");
                return 0;
        }
    }
}


