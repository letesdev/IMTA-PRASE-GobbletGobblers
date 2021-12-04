#include <iostream>

using namespace std;

#include "interfaceConsole.h"

Terminal::Terminal(){

}

void Terminal::printWhiteBoard(){
    cout <<"\t  1 \t  2 \t  3\n";
    for(int i=1;i<=3;i++){
		cout <<"  " << i;
        for(int j=1;j<=3;j++){
            cout <<"\t [ ]";
        }
        cout << endl;
    }
    return;
}

void Terminal::printPiece(size piece, player current_player){
    switch (piece){
    case NONE:
        cout << "\t [ ]";
        break;
    case SMALL:
        switch (current_player){
            case NO_PLAYER:
                cout << "\t [ ]";
                break;
            case PLAYER_1:
                cout << "\t [.]";
                break;
            case PLAYER_2:
                cout << "\t [x]";
                break;
            default:
                break;
        }
        break;
    case MEDIUM:
        switch (current_player){
            case NO_PLAYER:
                cout << "\t [ ]";
                break;
            case PLAYER_1:
                cout << "\t [o]";
                break;
            case PLAYER_2:
                cout << "\t [X]";
                break;
            default:
                break;
        }
        break;
    case LARGE:
        switch (current_player){
            case NO_PLAYER:
                cout << "\t [ ]";
                break;
            case PLAYER_1:
                cout << "\t [O]";
                break;
            case PLAYER_2:
                cout << "\t [#]";
                break;
            default:
                break;
        }
        break;
    default:
        break;
    }
}

void Terminal::printHouses(Board &board){
    cout << "+---------------------------------------------+\n";
    cout << "| Contenu maison ";
    cout << ANSI_COLOR_YELLOW "joueur #1: " ANSI_COLOR_RESET;
    cout << (board.get_nb_piece_in_house(PLAYER_1, SMALL) > 1 ? " . " : "   ");
    cout << (board.get_nb_piece_in_house(PLAYER_1, SMALL) > 0 ? " . " : "   ");
    cout << (board.get_nb_piece_in_house(PLAYER_1, MEDIUM) > 1 ? " o " : "   ");
    cout << (board.get_nb_piece_in_house(PLAYER_1, MEDIUM) > 0 ? " o " : "   ");
    cout << (board.get_nb_piece_in_house(PLAYER_1, LARGE) > 1 ? " O " : "   ");
    cout << (board.get_nb_piece_in_house(PLAYER_1, LARGE) > 0 ? " O |" : "   |") << endl;

    cout << "| Contenu maison ";
    cout << ANSI_COLOR_BLUE "joueur #2: " ANSI_COLOR_RESET;
    cout << (board.get_nb_piece_in_house(PLAYER_2, SMALL) > 1 ? " x " : "   ");
    cout << (board.get_nb_piece_in_house(PLAYER_2, SMALL) > 0 ? " x " : "   ");
    cout << (board.get_nb_piece_in_house(PLAYER_2, MEDIUM) > 1 ? " X " : "   ");
    cout << (board.get_nb_piece_in_house(PLAYER_2, MEDIUM) > 0 ? " X " : "   ");
    cout << (board.get_nb_piece_in_house(PLAYER_2, LARGE) > 1 ? " # " : "   ");
    cout << (board.get_nb_piece_in_house(PLAYER_2, LARGE) > 0 ? " # |" : "   |") << endl;
    cout << "+---------------------------------------------+" << endl;
    return;
}

void Terminal::printGameBoard(Board &board){
    printf("\t  1 \t  2 \t  3\n");
    for(int i=1;i<=board.getDimensions();i++){
		printf("  %d", i);
        for(int j=1;j<=board.getDimensions();j++){
            //printf("\t [ ]");
            printPiece(board.get_piece_size(i-1, j-1), board.get_place_holder(i-1, j-1));
        }
        printf("\n");
    }
    return;
}