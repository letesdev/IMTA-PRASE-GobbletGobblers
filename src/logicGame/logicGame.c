#include "../logicGame/logicGame.h"

void choix(board game, player current_player){
    int choixTour = 0, line = 0, column = 0, line_final = 0, column_final = 0, type = 1;
    int valide = 1;

    while (valide != 0){
        valide = 1;
        choixTour = check_input(1, 2, "\nVoulez-vous ajouter ou déplacer une pièce? (1/2) >");
        if (choixTour == 1){ /* Ajouter une pièce */
            line = check_input(1, 3, "Introduisez la ligne (1,2,3) :");
            column = check_input(1, 3, "Introduisez la colonne (1,2,3) :");
            type = check_input(1, 3, "Introduisez la taille (1,2,3) :");

            //check_turn(choixTour, type, line, column, line_final, column_final, &valide, current_player, game);
            // Il me semble qu'il y a pas besoin de vérifier le tour. 
            valide = place_piece(game, current_player, type, line - 1, column - 1);
            switch (valide){
                case 0:
                    //printf("\nSuccess!");
                    break;
                case 1:
                    printf(ANSI_COLOR_RED "\nThe piece is not available in the player's house."ANSI_COLOR_RESET);
                    break;
                case 2:
                    printf(ANSI_COLOR_RED "\nThe piece is to small to be put there."ANSI_COLOR_RESET);
                    break;
                case 3:
                    printf(ANSI_COLOR_RED "\nIllegal entry"ANSI_COLOR_RESET);
                    break;
                default:
                    break;
            }
        } else if (choixTour == 2){ /* Déplacer une pièce */
            line = check_input(1, 3, "Introduisez la ligne: ");
            column = check_input(1, 3, "Introduisez la colonne: ");
            line_final = check_input(1, 3, "Introduisez la ligne finale: ");
            column_final = check_input(1, 3, "Introduisez la colonne finale: ");

            //check_turn(choixTour, type, line, column, line_final, column_final, &valide, current_player, game);
            // Il me semble qu'il y a pas besoin de checker le tour. 
            valide = move_piece(game, line - 1, column - 1, line_final - 1, column_final - 1);
            switch (valide){
                case 0:
                    //printf("\nSuccess!");
                    break;
                case 1:
                    printf(ANSI_COLOR_RED "\nThere is no piece at the initial place."ANSI_COLOR_RESET);
                    break;
                case 2:
                    printf(ANSI_COLOR_RED "\nThe piece is too small to be put at the target place."ANSI_COLOR_RESET);
                    break;
                case 3:
                    printf(ANSI_COLOR_RED "\nIllegal entry"ANSI_COLOR_RESET);
                    break;
                default:
                    break;
            }
        }
    }
}



void check_turn(int choixTour, int type, int line, int column, int line_final, int column_final, int *valide, int current_player, board game)
{
    if (choixTour == 0){ // Ajouter une pièce
        /* Vérifications à faire: 
            - Est-ce que le current_player a toujours des pièces de cette taille?
            - Est-ce qu'il y a déjà une pièce de taille supérieure à celle du current_player?
        */
        valide = 0;

        if (type < get_piece_size(game, line, column)){
            printf("\nImpossible de placer votre pièce sur une pièce de taille supérieure !\n");
            *valide = 1;
        }

        if (!get_nb_piece_in_house(game, current_player, type)){
            printf("\nVous n'avez pas des pièces de ce type! \n");
            *valide = 1;
        }
    }else if (choixTour == 1){
        /* Vérifications à faire: 
            - Est-ce que la pièce appartient au current_player? 
            - Est-ce qu'il y a déjà une pièce de taille supérieure à celle du current_player?
            - Est-ce qu'il y a une pièce de taille supérieure sur cette pièce?
        */
        valide = 0;

        if (current_player != get_place_holder(game, line, column)){
            printf("\nLa pièce que vous essayer de déplacer n'est pas a vous! \n");
            *valide = 1;
        }

        if (current_player != get_place_holder(game, line, column) && get_place_holder(game, line, column) < get_piece_size(game, line_final, column_final)){
            printf("\nImpossible de déplacer votre pièce sur une pièce de taille supérieure !\n");
            *valide = 1;
        }
    }
}


/* Mode de jeu: deux joueurs */
int play1vs1(board game){
    int run = 1;
    /*  current_player 1 == Vous
        current_player 2 == Ami */
    player current_player = PLAYER_1; /* On commence tout le temps par le current_player 1*/

    while (run == 1){
        system("clear");
        printf("Mode de jeu: 1 contre 1\n");
        if (current_player == 1){
            printf("Tour du ");
            printf(ANSI_COLOR_YELLOW "joueur #1!\n" ANSI_COLOR_RESET);
        }else if (current_player == 2){
            printf("Tour du ");
            printf(ANSI_COLOR_BLUE "joueur #2!\n" ANSI_COLOR_RESET);
        }
        
        printHouses(game);
        printGameBoard(game);
        choix(game, current_player);
        
        if (current_player == 1){
            current_player = next_player(current_player);
        }else if (current_player == 2){
            current_player = next_player(current_player);
        }

        if (get_winner(game)!=0){
            run = 0;
        }
    }
    return (int) get_winner(game);
}
