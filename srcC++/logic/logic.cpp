#include <iostream>
#include <stdlib.h>
using namespace std;

#include "logic.h"
#include "board.h"
#include "../interface/interfaceConsole.h"

Logic::Logic(){

}

int Logic::check_input(int min, int max, string question){
    int input = 0;
    while (input < min || input > max)
    {
        cout << question;
        cin >>input;
    }
    return input;
}

void Logic::choix(Board &board, player current_player){
    int choixTour = 0, line = 0, column = 0, line_final = 0, column_final = 0, type = 1;
    int valide = 1;
    
    while (valide != 0){
        valide = 1;
        choixTour = this->check_input(1, 2, "\nVoulez-vous ajouter ou déplacer une pièce? (1/2) >");
        if (choixTour == 1){ /* Ajouter une pièce */
            line = this->check_input(1, 3, "Introduisez la ligne (1,2,3) :");
            column = this->check_input(1, 3, "Introduisez la colonne (1,2,3) :");
            type = this->check_input(1, 3, "Introduisez la taille (1,2,3) :");

            //check_turn(choixTour, type, line, column, line_final, column_final, &valide, current_player, game);
            // Il me semble qu'il y a pas besoin de vérifier le tour. 
            
            valide = board.place_piece((size) type, line - 1, column - 1);
            valide = 0;
            switch (valide){
                case 0:
                    //printf("\nSuccess!");
                    break;
                case 1:
                    cout << ANSI_COLOR_RED "\nThe piece is not available in the player's house." ANSI_COLOR_RESET<< endl;
                    break;
                case 2:
                    cout << ANSI_COLOR_RED "\nThe piece is to small to be put there." ANSI_COLOR_RESET<< endl;
                    break;
                case 3:
                    cout << ANSI_COLOR_RED "\nIllegal entry" ANSI_COLOR_RESET<< endl;
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
            valide = board.move_piece(line - 1, column - 1, line_final - 1, column_final - 1);
            switch (valide){
                case 0:
                    //printf("\nSuccess!");
                    break;
                case 1:
                    cout << ANSI_COLOR_RED "\nThere is no piece at the initial place." ANSI_COLOR_RESET << endl;
                    break;
                case 2:
                    cout << ANSI_COLOR_RED "\nThe piece is too small to be put at the target place." ANSI_COLOR_RESET<< endl;
                    break;
                case 3:
                    cout << ANSI_COLOR_RED "\nIllegal entry" ANSI_COLOR_RESET<< endl;
                    break;
                case 4:
                    cout << ANSI_COLOR_RED "\nThe piece is not yours!" ANSI_COLOR_RESET<< endl;
                default:
                    break;
            }
        }
    }
}

/* Mode de jeu: deux joueurs (pas de machine)*/
/*  current_player 1 == Vous
    current_player 2 == Ami */
int Logic::play1vs1(){
    Board tableau;
    Terminal t0;
    int run = 1;
    player current_player = tableau.next_player();

    while (run == 1){
        system("clear");
        cout << "Mode de jeu: 1 contre 1" << endl;
        cout << "Tour du ";
        if (current_player == PLAYER_1){
            cout << ANSI_COLOR_YELLOW "joueur #1!" ANSI_COLOR_RESET << endl;
        }else if (current_player == PLAYER_2){
            cout << ANSI_COLOR_BLUE "joueur #2!" ANSI_COLOR_RESET << endl;
        }
        
        t0.printHouses(tableau);
        t0.printGameBoard(tableau);
        choix(tableau, current_player);
        
        current_player = tableau.next_player();

        if (tableau.get_winner()!=0){
            run = 0;
            system("clear");
            t0.printGameBoard(tableau);
        }
    }
    return (int) tableau.get_winner();
}
