#include <iostream>
#include <stdlib.h>
using namespace std;

#include "logic.h"
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

void Logic::make_move(Board &board, player current_player){
    int choix = 0, line = 0, column = 0, line_final = 0, column_final = 0, type = 1;
    int valide = 1;
    
    while (valide != 0){
        valide = 1;
        choix = this->check_input(1, 2, "\nVoulez-vous ajouter ou déplacer une pièce? (1/2) >");
        if (choix == 1){ /* Ajouter une pièce */
            line = this->check_input(1, 3, "Introduisez la ligne (1,2,3) :");
            column = this->check_input(1, 3, "Introduisez la colonne (1,2,3) :");
            type = this->check_input(1, 3, "Introduisez la taille (1,2,3) :");
            
            valide = board.place_piece((size) type, line - 1, column - 1);
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
        } else if (choix == 2){ /* Déplacer une pièce */
            line = check_input(1, 3, "Introduisez la ligne: ");
            column = check_input(1, 3, "Introduisez la colonne: ");
            line_final = check_input(1, 3, "Introduisez la ligne finale: ");
            column_final = check_input(1, 3, "Introduisez la colonne finale: ");

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

void Logic::simulate_move(Board &board, player current_player, bot current_bot){
    vector<int> legal_lines; 
    vector<int> legal_columns;
    vector<int> legal_sizes;
    int valide = 1;

    vector<int> legal_move_source_lines; 
    vector<int> legal_move_source_column;
    vector<int> legal_move_source_size;

    vector<int> legal_move_target_lines; 
    vector<int> legal_move_target_column;
    vector<int> legal_move_target_size;

    
    Board copye_tableau(board);

    switch ((bot) current_bot - 1){
        case RANDOM:{
            while (valide != 0){
                //int random_move = this->check_input(1, 2, "\nVoulez-vous ajouter ou déplacer une pièce? (1/2) >");
                int random_move = rand() % 2 + 1;
                
                if (random_move == 1){ // place piece
                    board.get_legal_place(legal_lines, legal_columns, legal_sizes);
                    while (valide != 0){
                        int random_choice = rand() % legal_lines.size() + 1;
                        valide = board.place_piece((size) legal_sizes[random_choice], legal_lines[random_choice], legal_columns[random_choice]);
                    }
                }else{ // move piece
                    board.get_legal_moves(legal_move_source_lines, legal_move_source_column, legal_move_source_size, legal_move_target_lines, legal_move_target_column, legal_move_target_size);
                    if (!legal_move_source_lines.empty()){
                        /*for(std::size_t i = 0; i < legal_move_source_lines.size(); ++i) {
                            cout << "source (" << legal_move_source_lines[i] << ", " << legal_move_source_column[i] << ") -> (" << legal_move_target_lines[i] << ", " << legal_move_target_column[i] << ")" << endl;
                        }*/
                        while (valide != 0){
                            int random_choice = rand() % legal_move_source_lines.size() + 1;
                            valide = board.move_piece(legal_move_source_lines[random_choice], legal_move_source_column[random_choice], legal_move_target_lines[random_choice], legal_move_target_column[random_choice]);
                        }
                    }
                }
            }
            break;}
        
        case ONELAYER:{
            while (valide != 0){
                
                //int random_move = rand() % 2 + 1;
                
                copye_tableau.get_legal_place(legal_lines, legal_columns, legal_sizes);
                for(std::size_t i = 0; i < legal_lines.size(); ++i) {
                    copye_tableau.place_piece((size) legal_sizes[i], legal_lines[i], legal_columns[i]);
                    if (copye_tableau.get_winner()==2){
                        valide = board.place_piece((size) legal_sizes[i], legal_lines[i], legal_columns[i]);
                        break;
                    }
                }
                copye_tableau.get_legal_moves(legal_move_source_lines, legal_move_source_column, legal_move_source_size, legal_move_target_lines, legal_move_target_column, legal_move_target_size);
                if (!legal_move_source_lines.empty()){
                    for(std::size_t i = 0; i < legal_move_source_lines.size(); ++i) {
                        copye_tableau.move_piece(legal_move_source_lines[i], legal_move_source_column[i], legal_move_target_lines[i], legal_move_target_column[i]);
                        if (copye_tableau.get_winner()== 2){
                            valide = board.move_piece(legal_move_source_lines[i], legal_move_source_column[i], legal_move_target_lines[i], legal_move_target_column[i]);
                            break;
                        }
                    }
                }
                if (valide !=0){
                    int random_move = rand() % 2 + 1;
                    if (random_move == 1){ // place piece
                        //board.get_legal_place(legal_lines, legal_columns, legal_sizes);
                        while (valide != 0){
                            int random_choice = rand() % legal_lines.size() + 1;
                            valide = board.place_piece((size) legal_sizes[random_choice], legal_lines[random_choice], legal_columns[random_choice]);
                        }
                    }else{ // move piece
                        //board.get_legal_moves(legal_move_source_lines, legal_move_source_column, legal_move_source_size, legal_move_target_lines, legal_move_target_column, legal_move_target_size);
                        if (!legal_move_source_lines.empty()){
                            /*for(std::size_t i = 0; i < legal_move_source_lines.size(); ++i) {
                                cout << "source (" << legal_move_source_lines[i] << ", " << legal_move_source_column[i] << ") -> (" << legal_move_target_lines[i] << ", " << legal_move_target_column[i] << ")" << endl;
                            }*/
                            while (valide != 0){
                                int random_choice = rand() % legal_move_source_lines.size() + 1;
                                valide = board.move_piece(legal_move_source_lines[random_choice], legal_move_source_column[random_choice], legal_move_target_lines[random_choice], legal_move_target_column[random_choice]);
                            }
                        }
                    }
                }
            }
            break;}
        /*
        case TWOLAYER:
        
            break;

        case INVINCIBOT:
        
            break;*/
        
        default:
            break;
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
        make_move(tableau, current_player);
        
        current_player = tableau.next_player();

        if (tableau.get_winner()!=0){
            run = 0;
            system("clear");
            t0.printGameBoard(tableau);
        }
    }
    return (int) tableau.get_winner();
}

bot Logic::askBotType(){
    int valor; 

    valor = check_input(1, 1, "Choisisez un type de bot, puis appuyez ENTER:\n \
         1. Random. \n \
         2. One Layer. \n \
        Option choisie: ");
        /*
         3. Two Layer. \n \
         4. Invincible. \n \*/
    return (bot) valor;
}

/* Mode de jeu: deux joueurs (pas de machine)*/
/*  current_player 1 == Vous
    current_player 2 == Bot */
int Logic::play1vsbot(){
    Board tableau;
    Terminal t0;
    bot current_bot;
    int run = 1;
    
    player current_player = tableau.next_player();
    current_bot = askBotType();
    //current_bot = ONELAYER;
    while (run == 1){
        system("clear");
        cout << "Mode de jeu: Joueur contre Bot" << endl;
        cout << "Tour du ";
        if (current_player == PLAYER_1){
            cout << ANSI_COLOR_YELLOW "joueur #1!" ANSI_COLOR_RESET << endl;
        }else if (current_player == PLAYER_2){
            cout << ANSI_COLOR_BLUE "bot!" ANSI_COLOR_RESET << endl;
        }
        
        t0.printHouses(tableau);
        t0.printGameBoard(tableau);
        if (current_player == PLAYER_1){
            make_move(tableau, current_player);
        }else if (current_player == PLAYER_2){
            simulate_move(tableau, current_player, current_bot);
        }

        if (tableau.get_winner()!=0){
            run = 0;
            system("clear");
            t0.printGameBoard(tableau);
        }else{
            current_player = tableau.next_player();
        }
        
    }
    return (int) tableau.get_winner();
}