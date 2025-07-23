#include <iostream>
#include "helpers.hpp"
#include "knight.hpp"
#include "piece.hpp"
using namespace std;

Piece* board[8][8];

int main(){

    Piece * whiteknight1 = new Knight("white", 'a', 1);

    for (int i=0;i<8;i++){
        for (int j=0;j<8;j++){
            board[i][j] = nullptr;
        };
    }   
    board[0][1] = whiteknight1;
    print_board(board);

};
