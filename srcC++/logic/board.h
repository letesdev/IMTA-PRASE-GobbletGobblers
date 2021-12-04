#ifndef BOARD_H
#define BOARD_H

enum sizes_e {NONE, SMALL, MEDIUM, LARGE};
typedef enum sizes_e size;

enum players_e {NO_PLAYER, PLAYER_1, PLAYER_2};
typedef enum players_e player;

class Board{
    private :
        static const int dimensions = 3;
        static const int nb_size    = 3;
        static const int nb_players = 2;
        player current_player = PLAYER_2;
        int size_matrix [3][dimensions*dimensions] = {0};
        int player_matrix [3][dimensions*dimensions] = {0};
        //int low_size_matrix [2][dimensions*dimensions] = {0};
        //int low_player_matrix [2][dimensions*dimensions] = {0};
        int houses_matrix [nb_players][3*2]; // 2 pièces de chaque size, pour chaque joueur
        //            0 1 2 3 4 5
        // player 1: [. . o o O O]
        // player 2: [x x X X # #]
    public:
        // Constructeur par défaut
        Board(); // new_game()
        // Constructeur de copie
        Board(Board const &original_game);
        // Destructeur
        ~Board();

        // Services
        player get_place_holder(int line, int column);
        size get_piece_size(int line, int column);
        player get_winner();
        player next_player();
        int get_nb_piece_in_house(player checked_player, size piece_size);
        void take_piece_from_house(player checked_player, size piece_size);
        int place_piece(size piece_size, int line, int column);
        int move_piece(int source_line, int source_column, int target_line, int target_column);

        //getters
        int getDimensions();
};
#endif //BOARD_H