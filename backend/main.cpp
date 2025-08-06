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

    for (int i=0;i<8;i++){
        for (int j=0;j<8;j++){
            board[i][j] = nullptr;
        };
    }   

    board[7][0] = new Rook("W", 'a', 1);
    board[7][1] = new Knight("W", 'b', 1);
    board[7][2] = new Bishop("W", 'c', 1);
    board[7][3] = new King("W", 'e', 1);
    board[7][4] = new Queen("W", 'd', 1);
    board[7][5] = new Bishop("W", 'f', 1);
    board[7][6] = new Knight("W", 'g', 1);
    board[7][7] = new Rook("W", 'h', 1);
    for (int i = 0; i < 8; i++){
        board[the_maggie_function(2) - 1][i] = new Pawn("W", number_to_letter(i), 2);
    }
    board[0][0] = new Rook("B", 'a', 8);
    board[0][1] = new Knight("B", 'b', 8);
    board[0][2] = new Bishop("B", 'c', 8);
    board[0][3] = new King("B", 'e', 8);
    board[0][4] = new Queen("B", 'd', 8);
    board[0][5] = new Bishop("B", 'f', 8);
    board[0][6] = new Knight("B", 'g', 8);
    board[0][7] = new Rook("B", 'h', 8);
    for (int i = 0; i < 8; i++){
        board[the_maggie_function(7) - 1][i] = new Pawn("B", number_to_letter(i), 7);
    }


    //calc possible squares for all pieces
    for (auto& row : board){
        for (auto& piece : row){
            if (piece != nullptr){
                piece->calc_possible_squares();
                cout << *piece << "possible squares: {";
                for (auto& square : piece->possible_squares){
                    cout << square.first << square.second << ", ";
                }
                cout << "}" << endl;
            }
        }
    }

    print_board();

};
