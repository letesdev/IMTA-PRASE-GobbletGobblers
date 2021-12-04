#include "../interface/interfaceConsole.h"

void printWhiteBoard(){
    printf("\t  1 \t  2 \t  3\n");
    for(int i=1;i<=NB_SIZE;i++){
		printf("  %d", i);
        for(int j=1;j<=NB_SIZE;j++){
            printf("\t [ ]");
        }
        printf("\n");
    }
    return;
}

void printPiece(size piece, player current_player){
    switch (piece){
    case NONE:
        printf("\t [ ]");
        break;
    case SMALL:
        switch (current_player){
            case NO_PLAYER:
                printf("\t [ ]");
                break;
            case PLAYER_1:
                printf("\t [º]");
                break;
            case PLAYER_2:
                printf("\t [x]");
                break;
            default:
                break;
        }
        break;
    case MEDIUM:
        switch (current_player){
            case NO_PLAYER:
                printf("\t [ ]");
                break;
            case PLAYER_1:
                printf("\t [o]");
                break;
            case PLAYER_2:
                printf("\t [X]");
                break;
            default:
                break;
        }
        break;
    case LARGE:
        switch (current_player){
            case NO_PLAYER:
                printf("\t [ ]");
                break;
            case PLAYER_1:
                printf("\t [O]");
                break;
            case PLAYER_2:
                printf("\t [#]");
                break;
            default:
                break;
        }
        break;
    default:
        break;
    }
}

void printHouses(board game){
    printf("+---------------------------------------+\n");
    printf("| Contenu maison ");
    printf(ANSI_COLOR_YELLOW "joueur #1" ANSI_COLOR_RESET);
    printf(": %s %s %s %s %s %s |\n",
            get_nb_piece_in_house(game, PLAYER_1, SMALL) > 1 ? "º" : " ",
            get_nb_piece_in_house(game, PLAYER_1, SMALL) > 0 ? "º" : " ",
            get_nb_piece_in_house(game, PLAYER_1, MEDIUM) > 1 ? "o" : " ",
            get_nb_piece_in_house(game, PLAYER_1, MEDIUM) > 0 ? "o" : " ",
            get_nb_piece_in_house(game, PLAYER_1, LARGE) > 1 ? "O" : " ",
            get_nb_piece_in_house(game, PLAYER_1, LARGE) > 0 ? "O" : " ");
    printf("| Contenu maison ");
    printf(ANSI_COLOR_BLUE "joueur #2" ANSI_COLOR_RESET);
    printf(": %s %s %s %s %s %s |\n",
            get_nb_piece_in_house(game, PLAYER_2, SMALL) > 1 ? "x" : " ",
            get_nb_piece_in_house(game, PLAYER_2, SMALL) > 0 ? "x" : " ",
            get_nb_piece_in_house(game, PLAYER_2, MEDIUM) > 1 ? "X" : " ",
            get_nb_piece_in_house(game, PLAYER_2, MEDIUM) > 0 ? "X" : " ",
            get_nb_piece_in_house(game, PLAYER_2, LARGE) > 1 ? "#" : " ",
            get_nb_piece_in_house(game, PLAYER_2, LARGE) > 0 ? "#" : " ");
    printf("+---------------------------------------+\n");
    return;
}

void printGameBoard(board game){
    printf("\t  1 \t  2 \t  3\n");
    for(int i=1;i<=NB_SIZE;i++){
		printf("  %d", i);
        for(int j=1;j<=NB_SIZE;j++){
            //printf("\t [ ]");
            printPiece(get_piece_size(game, i-1, j-1), get_place_holder(game, i-1, j-1));
        }
        printf("\n");
    }
    return;
}