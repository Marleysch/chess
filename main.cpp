#include <iostream>
#include "helpers.hpp"
#include "knight.hpp"
#include "piece.hpp"
using namespace std;


int main(){

    for (int i=0;i<8;i++){
        for (int j=0;j<8;j++){
            board[i][j] = nullptr;
        };
    }   
    
    Piece * whiteknight1 = new Knight("W", 'b', 1);
    print_board();
    whiteknight1->move({'d',2});
    print_board();

    for (const auto& square : whiteknight1->possible_squares){
        cout << square.first << square.second << endl;
    }

};
