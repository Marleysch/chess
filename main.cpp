#include <iostream>
#include "helpers.hpp"
#include "knight.hpp"
#include "piece.hpp"
using namespace std;

extern Piece* board[8][8];

int main(){
    // for (int i=0;i<8;i++){
    //     for (int j=0;j<8;j++){
    //         board[i][j] = nullptr;
    //     };
    // }   
    // for (int i=0;i<8;i++){
    //     cout << endl;
    //     for (int j=0;j<8;j++){
    //         cout << *board[i][j];
    //     }
    // }
    Piece * whiteknight1 = new Knight("white", 'a', 1);
    for (auto& square : whiteknight1->possible_squares){
        cout << square.first << square.second << endl;
    }
    whiteknight1->move({'c',2});
    for (auto& square : whiteknight1->possible_squares){
        cout << square.first << square.second << endl;
    }

};