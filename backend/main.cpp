#include <iostream>
#include "helpers.hpp"
#include "knight.hpp"
#include "piece.hpp"
#include "rook.hpp"
#include "king.hpp"
#include "bishop.hpp"
#include "queen.hpp"
#include "pawn.hpp"
using namespace std;


int main(){
    cout << "running main" << endl << endl;

    initialize_game();

    print_board();

};
