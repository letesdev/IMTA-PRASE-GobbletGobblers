#include <iostream>

using namespace std;

#include "board.h"

// Constructeur par défaut
Board::Board(){
    for (int i = 0; i < nb_players; i++){
        for (int j = 0; j < 3*2; j++){
            houses_matrix[i][j] = 1;
        }
    }
}

// Constructeur de copie
Board::Board(Board const &original_game){
    current_player = original_game.current_player;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < dimensions*dimensions; i++){
            size_matrix[i][j] = original_game.size_matrix[i][j];
            player_matrix[i][j] = original_game.player_matrix[i][j];
        }
    }
    for (int i = 0; i < nb_players; i++){
        for (int j = 0; j < 3*2; j++){
            houses_matrix[i][j] = original_game.houses_matrix[i][j];
        }
    }
    /* for (int i = 0; i < dimensions*dimensions; i++){
        size_matrix[i] = original_game.size_matrix[i];
        player_matrix[i] = original_game.player_matrix[i];
    }
     for (int i = 0; i < 2; i++){
        for (int j = 0; j < dimensions*dimensions; i++){
            low_size_matrix[i][j] = original_game.low_size_matrix[i][j];
            low_player_matrix[i][j] = original_game.low_player_matrix[i][j];
        }
    } */
}

// Destructeur
Board::~Board(){
    
}

player Board::get_place_holder(int line, int column){
    if (line < 0 || line > dimensions || column < 0 || column > dimensions){
        throw out_of_range("Caisse non trouvable!");
    }else{
        return (player) player_matrix[2][line*3+column];
    }
}

size Board::get_piece_size(int line, int column){
    if (line < 0 || line > dimensions || column < 0 || column > dimensions){
        throw out_of_range("Caisse non trouvable!");
    }else{
        return (size) size_matrix[2][line*3+column];
    }
}

player Board::get_winner(){
    for(int i = 0; i < dimensions; i++){ 
        if (this->get_place_holder(i, 0) == this->get_place_holder(i, 1) && this->get_place_holder(i, 1) == this->get_place_holder(i, 2)){ // ligne
            return this->get_place_holder(i, 2);
        }
        if (this->get_place_holder(0, i) == this->get_place_holder(1, i) && this->get_place_holder(1, i) == this->get_place_holder(2, i)){ // colonne
            return this->get_place_holder(2, i);
        }
    }
    if (this->get_place_holder(0,0) == this->get_place_holder(1,1) && this->get_place_holder(1,1) == this->get_place_holder(2,2)){ // diagonale 
        return this->get_place_holder(2,2);
    }
    if (this->get_place_holder(0,2) == this->get_place_holder(1,1) && this->get_place_holder(1,1) == this->get_place_holder(2,0)){ // diagonale 
        return this->get_place_holder(2,0);
    }
    return NO_PLAYER;
}
player Board::next_player(){
    if (current_player == PLAYER_1){
        current_player = PLAYER_2;
    }else{
        current_player = PLAYER_1;
    }
    return current_player;
}

int Board::get_nb_piece_in_house(player checked_player, size piece_size){
    int player = 0; // PLAYER_1 choisi par defaut
    if (checked_player == PLAYER_2){
        player = 1;
    }
    int taille = 0;
    switch (piece_size){
        case SMALL:
            taille = 0;
            break;
        case MEDIUM:
            taille = 2;
            break;
        case LARGE:
            taille = 4;
            break;
        case NONE:
        default:
            throw out_of_range("Size introuvable!");
    }
    return houses_matrix[player][taille] + houses_matrix[player][taille + 1];
}

void Board::take_piece_from_house(player checked_player, size piece_size){
    int player = 0; // PLAYER_1 choisi par defaut
    if (checked_player == PLAYER_2){
        player = 1;
    }
    int taille = 0;
    switch (piece_size){
        case SMALL:
            taille = 0;
            break;
        case MEDIUM:
            taille = 2;
            break;
        case LARGE:
            taille = 4;
            break;
        case NONE:
        default:
            throw out_of_range("Size introuvable!");
    }
    if (houses_matrix[player][taille] == 0){
        houses_matrix[player][taille + 1] = 0;
    }else{
        houses_matrix[player][taille] = 0;
    }
    return;
}

int Board::place_piece(size piece_size, int line, int column){
    if (line < 0 || line > dimensions || column < 0 || column > dimensions){
        return 3; // Ligne ou colonne incorrecte
    }
    if (get_nb_piece_in_house(current_player, piece_size) == 0){
        return 1; // Le joueur n'a pas plus de pièces de cette taille dans sa maison
    }
    if (get_piece_size(line, column) >= piece_size){
        return 2; // La pièce a placer est plus petite ou de même taille que la piece présente dans le tableau
    }
    
    if (size_matrix[2][line*3+column] != 0){ // Il y a déjà une pièce dans cette position
        if (size_matrix[1][line*3+column] != 0){ // Il y a déjà une pièce plus petite dans cette position
            size_matrix[0][line*3+column] = size_matrix[1][line*3+column]; //Je fais une copie de la piece
            player_matrix[0][line*3+column] = player_matrix[1][line*3+column]; // Je fais une copie du joueur
        }
        size_matrix[1][line*3+column] = size_matrix[2][line*3+column]; //Je fais une copie de la piece
        player_matrix[1][line*3+column] = player_matrix[2][line*3+column]; // Je fais une copie du joueur
    }
    size_matrix[2][line*3+column] = (int) piece_size;
    player_matrix[2][line*3+column] = (int) current_player;

    this->take_piece_from_house(current_player, piece_size);
    return 0;
}

int Board::move_piece(int source_line, int source_column, int target_line, int target_column){
    if (get_place_holder(source_line, source_column) != current_player){
        return 4; // La pièce n'appartient pas au joueur. 
    }
    if (target_line < 0 || target_line > dimensions || target_column < 0 || target_column > dimensions){
        return 3; // Ligne ou colonne incorrecte
    }
    if (get_piece_size(target_line, target_column) >= get_piece_size(source_line, source_column)){
        return 2; // La pièce a placer est plus petite ou de même taille que la piece présente dans le tableau
    }
    if (get_piece_size(source_line, source_column) == NONE){
        return 1; // Il n'y a pas de piece à l'emplacement initial
    }

    if (size_matrix[2][target_line*3+target_column] != 0){ // Il y a déjà une pièce dans cette position
        if (size_matrix[1][target_line*3+target_column] != 0){ // Il y a déjà une pièce plus petite dans cette position
            size_matrix[0][target_line*3+target_column] = size_matrix[1][target_line*3+target_column]; //Je fais une copie de la piece
            player_matrix[0][target_line*3+target_column] = player_matrix[1][target_line*3+target_column]; // Je fais une copie du joueur
        }
        size_matrix[1][target_line*3+target_column] = size_matrix[2][target_line*3+target_column]; //Je fais une copie de la piece
        player_matrix[1][target_line*3+target_column] = player_matrix[2][target_line*3+target_column]; // Je fais une copie du joueur
    }
    size_matrix[2][target_line*3+target_column] = size_matrix[2][source_line*3+source_column];
    player_matrix[2][target_line*3+target_column] = player_matrix[2][source_line*3+source_column];

    size_matrix[2][source_line*3+source_column] = size_matrix[1][source_line*3+source_column];
    player_matrix[2][source_line*3+source_column] = player_matrix[1][source_line*3+source_column];

    size_matrix[1][source_line*3+source_column] = size_matrix[0][source_line*3+source_column];
    player_matrix[1][source_line*3+source_column] = player_matrix[0][source_line*3+source_column];
    
    size_matrix[0][source_line*3+source_column] = 0;
    player_matrix[0][source_line*3+source_column] = 0;

    return 0;
}

/*void Board::get_legal_moves(int legal_lines[], int legal_columns[]){
    int lines[];
    for (int line = 0; line < dimensions; line++){
        for (int column = 0; column < dimensions; column++){
            if (get_piece_size(line, column) == NONE){
                i++;
            }
        }
    }
}*/

void Board::get_legal_place(vector<int> &lines, vector<int> &columns, std::vector<int> &sizes){
    for (int line = 0; line < dimensions; line++){
        for (int column = 0; column < dimensions; column++){
            if (get_piece_size(line, column) == MEDIUM && get_nb_piece_in_house(current_player, LARGE) > 0){
                lines.push_back(line);
                columns.push_back(column);
                sizes.push_back(3);
            }
            if (get_piece_size(line, column) == SMALL && get_nb_piece_in_house(current_player, MEDIUM) > 0){
                lines.push_back(line);
                columns.push_back(column);
                sizes.push_back(2);
            }
            if (get_piece_size(line, column) == SMALL && get_nb_piece_in_house(current_player, LARGE) > 0){
                lines.push_back(line);
                columns.push_back(column);
                sizes.push_back(3);
            }
            if (get_piece_size(line, column) == NONE && get_nb_piece_in_house(current_player, LARGE) > 0){
                lines.push_back(line);
                columns.push_back(column);
                sizes.push_back(3);
            }
            if (get_piece_size(line, column) == NONE && get_nb_piece_in_house(current_player, MEDIUM) > 0){
                lines.push_back(line);
                columns.push_back(column);
                sizes.push_back(2);
            }
            if (get_piece_size(line, column) == NONE && get_nb_piece_in_house(current_player, SMALL) > 0){
                lines.push_back(line);
                columns.push_back(column);
                sizes.push_back(1);
            }
        }
    }
}

void Board::get_legal_moves(std::vector<int> &source_lines, std::vector<int> &source_columns, std::vector<int> &source_sizes, std::vector<int> &target_lines, std::vector<int> &target_columns, std::vector<int> &target_sizes){
    vector<int> legal_move_source_lines; 
    vector<int> legal_move_source_column;
    vector<int> legal_move_source_size;
    for (int line = 0; line < dimensions; line++){
        for (int column = 0; column < dimensions; column++){
            if (get_place_holder(line, column) == current_player){
                legal_move_source_lines.push_back(line);
                legal_move_source_column.push_back(column);
                legal_move_source_size.push_back(get_piece_size(line, column));
            }
        }
    }
    /*cout << "ya" << endl;
    if (!legal_move_source_lines.empty()){
        for(std::size_t i = 0; i < legal_move_source_lines.size(); ++i) {
            std::cout << legal_move_source_lines[i] << " " << legal_move_source_column[i] << endl;
        }
    }*/
    
    if (!legal_move_source_size.empty()){
        for (int line = 0; line < dimensions; line++){
            for (int column = 0; column < dimensions; column++){
                if (get_place_holder(line, column) != current_player){
                    for (std::size_t i = 0; i < legal_move_source_size.size(); ++i){
                        if (legal_move_source_size[i] > get_piece_size(line, column)){
                            source_lines.push_back(legal_move_source_lines[i]);
                            source_columns.push_back(legal_move_source_column[i]);
                            target_lines.push_back(line);
                            target_columns.push_back(line);
                            //cout << "source (" << legal_move_source_lines[i] << ", " << legal_move_source_column[i] << ") -> (" << line << ", " << column << ")" << endl;
                        }
                    }
                }
            }
        }
    }
    
}


int Board::getDimensions(){
    return dimensions;
}