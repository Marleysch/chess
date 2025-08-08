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
using namespace std;


int main(){
    cout << "running main" << endl << endl;

    crow::SimpleApp app;

    initialize_game();

    // board[0][0]->move(pair<char, int> {'a', 1>});

    // CROW_ROUTE(app, )

    print_board();

};
