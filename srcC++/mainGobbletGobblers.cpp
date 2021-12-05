#include <iostream>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include "logic/board.h"
#include "logic/logic.h"
#include "interface/interfaceConsole.h"

using namespace std;
int menuPrincipal(){
    int valor;

    cout <<"   ______      __    __    __     __       ______      __    __    __              \n";
    cout <<"  / ____/___  / /_  / /_  / /__  / /_     / ____/___  / /_  / /_  / /__  __________\n";
    cout <<" / / __/ __ \\/ __ \\/ __ \\/ / _ \\/ __/    / / __/ __ \\/ __ \\/ __ \\/ / _ \\/ ___/ ___/\n";
    cout <<"/ /_/ / /_/ / /_/ / /_/ / /  __/ /_     / /_/ / /_/ / /_/ / /_/ / /  __/ /  (__  ) \n";
    cout <<"\\____/\\____/_.___/_.___/_/\\___/\\__/     \\____/\\____/_.___/_.___/_/\\___/_/  /____/  \n";

    cout <<"-----------------------------------------------------------------------------------------\n";
    cout <<"  _____         __             ____          __         \n";
    cout <<" / ___/__ _____/ /__  ___     / __/__ ____  / /____  ___\n";
    cout <<"/ /__/ _ `/ __/ / _ \\(_-<    _\\ \\/ _ `/ _ \\/ __/ _ \\(_-<\n";
    cout <<"\\___/\\_,_/_/ /_/\\___/___/   /___/\\_,_/_//_/\\__/\\___/___/\n";
    cout <<"\n";

    cout <<"Choisisez une option pour continuer, puis appuyez ENTER:\n \
    \t 1. Deux joueurs. \n \
    \t 2. Joueur vs Bot. \n \
    \t *N'importe quel numéro pour sortir...*\n \
    Option choisie: ";
    cin >> valor;
    
    return valor;
}

int main(){
    int playerG = 0;                /* Joueur vainqueur  */
    Logic l0;
    while (1){
        system("clear");            /* Clear Screen */
        switch (menuPrincipal()){
            case 1:                 /* Mode de jeu: deux joueurs */
                playerG = l0.play1vs1();
                //destroy_game(game);
                cout <<"Victoire du joueur " << playerG << "!!!" << endl;
                cout <<"Au revoir!" << endl;
                return 0;
            case 2:                 /* Mode de jeu: machine vs current_player */
                srand(time(NULL));
                playerG = l0.play1vsbot();
                if (playerG == PLAYER_1){
                    cout <<"Victoire du bot !!!" << endl;
                }else{
                    cout <<"Victoire du joueur " << playerG << "!!!" << endl;
                }
                cout <<"Au revoir!" << endl;
                return 0;
            /*case '3':
                autrefonction();
                continue; */
            case 0:
            /* Sortie */
            default:
                cout << "Au revoir!" << endl;
                return 0;
        }
    }
}