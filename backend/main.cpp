#include <iostream>
#include "helpers.hpp"
#include "knight.hpp"
#include "piece.hpp"
#include "rook.hpp"
#include "king.hpp"
#include "bishop.hpp"
#include "queen.hpp"
#include "pawn.hpp"
#include "crow.h"
#include "corshandler.hpp"
using namespace std;


int main(){
    cout << "running main" << endl << endl;

    crow::App<CORSHandler> app;

    initialize_game();

    cout << "pawn at a2: " << board[6][0]->curr_square.first << board[6][0]->curr_square.second << endl;

    for (auto& row : board){
        for (auto& piece : row){
            if (piece != nullptr){
                cout << *piece  << "at " << piece->curr_square.first << piece->curr_square.second << "possible squares: ";

                for (auto& space : piece->possible_squares){
                    cout << space.first << space.second << ",";
                }
                cout << endl << endl;
            }
        }   
    }
    cout << endl;

    board[6][0]->move({'a',4});

    print_board();

    CROW_ROUTE(app, "/board")([](){

        return build_client_board();
    });

    CROW_ROUTE(app, "/<int>/<int>/<int>/<int>")([](int p1rank, int p1row, int p2rank, int p2row){

        cout << "source space: " << p1rank << p1row << endl;
        cout << "target space: " << p2rank << p2row << endl;

        char p2rankletter = number_to_letter(p2rank + 1);
        p2row = the_maggie_function(p2row + 1);

        cout << "target space: " << p2rankletter << p2row << endl;

        bool result = board[p1row][p1rank]->move({p2rankletter, p2row});

        cout << result << endl;

        print_board();

        return build_client_board();

    });

    app.port(18080).multithreaded().run();

};
