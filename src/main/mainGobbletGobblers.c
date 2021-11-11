#include "mainGobbletGobblers.h"


/**
 * @file mainGobbletGobblers.c
 * @brief Gobblet Gobblers game launcher. 
 * 
 */


int menuPrincipal(){
    int valor;

    printf("   ______      __    __    __     __       ______      __    __    __              \n");
    printf("  / ____/___  / /_  / /_  / /__  / /_     / ____/___  / /_  / /_  / /__  __________\n");
    printf(" / / __/ __ \\/ __ \\/ __ \\/ / _ \\/ __/    / / __/ __ \\/ __ \\/ __ \\/ / _ \\/ ___/ ___/\n");
    printf("/ /_/ / /_/ / /_/ / /_/ / /  __/ /_     / /_/ / /_/ / /_/ / /_/ / /  __/ /  (__  ) \n");
    printf("\\____/\\____/_.___/_.___/_/\\___/\\__/     \\____/\\____/_.___/_.___/_/\\___/_/  /____/  \n");

    printf("-----------------------------------------------------------------------------------------\n");
    printf("  _____         __             ____          __         \n");
    printf(" / ___/__ _____/ /__  ___     / __/__ ____  / /____  ___\n");
    printf("/ /__/ _ `/ __/ / _ \\(_-<    _\\ \\/ _ `/ _ \\/ __/ _ \\(_-<\n");
    printf("\\___/\\_,_/_/ /_/\\___/___/   /___/\\_,_/_//_/\\__/\\___/___/\n");
    printf("\n");

    printf("Choisisez une option pour continuer, puis appuyez ENTER:\n \
    \t 1. Deux joueurs. \n \
    \t *N'importe quel numéro pour sortir...*\n \
    Option choisie: ");
    scanf("%d", &valor);
    
    return valor;
}

int main(int args, char **argv){
	int playerG = 0;                /* Joueur vainqueur  */
    board game = new_game();        /* Initialisation du tableau (voir board.h) */
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
            /*case '3':
                autrefonction();
                continue; */
            case 0:
            /* Sortie */
            default:
                printf("Au revoir!\n");
                return 0;
        }
    }
}


