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

    CROW_ROUTE(app, "/board")([](){

        return build_client_board();
    });

    CROW_ROUTE(app, "/<int>/<int>/<int>/<int>")([](int p1rank, int p1row, int p2rank, int p2row){

        board[p1row][p1rank]->move({number_to_letter(p2rank + 1), the_maggie_function(p2row + 1)});

        return build_client_board();

    });

    app.port(18080).multithreaded().run();

};
