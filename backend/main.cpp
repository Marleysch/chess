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
    string color = "white";

    crow::App<CORSHandler> app;

    initialize_game();

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

    CROW_ROUTE(app, "/color")([&color](){
        string old_color;
        if (color == "white"){
            old_color = color;
            color = "black";
        }
        else {
            old_color = color;
            color = "white";
        }
        return old_color;
    });

    app.port(18080).multithreaded().run();

};
