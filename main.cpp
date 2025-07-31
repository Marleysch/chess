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

//DONT FORGET TO CHECK FOR CHECK
int main(){
    cout << "running" << endl << endl;

    for (int i=0;i<8;i++){
        for (int j=0;j<8;j++){
            board[i][j] = nullptr;
        };
    }   
    
    print_board();

    //only have pointers in the board itself dont use these
    Piece * whiterook1 = new Rook("W", 'a', 1);
    Piece * whiteknight1 = new Knight("W", 'b', 1);
    Piece * whitebishop1 = new Bishop("W", 'c', 1);
    Piece * whiteking = new King("W", 'e', 1);
    Piece * whitequeen = new Queen("W", 'd', 1);
    Piece * whitebishop2 = new Bishop("W", 'f', 1);
    Piece * whiteknight2 = new Knight("W", 'g', 1);
    Piece * whiterook2 = new Rook("W", 'h', 1);
    for (int i = 0; i < 8; i++){
        board[the_maggie_function(2) - 1][i] = new Pawn("W", number_to_letter(i), 2);
    }
    Piece * blackrook1 = new Rook("B", 'a', 8);
    // Piece * blackknight1 = new Knight("B", 'b', 8);
    Piece * blackbishop1 = new Bishop("B", 'c', 8);
    Piece * blackking = new King("B", 'e', 8);
    Piece * blackqueen = new Queen("B", 'd', 8);
    Piece * blackbishop2 = new Bishop("B", 'f', 8);
    Piece * blackknight2 = new Knight("B", 'g', 8);
    Piece * blackrook2 = new Rook("B", 'h', 8);
    for (int i = 0; i < 8; i++){
        board[the_maggie_function(7) - 1][i] = new Pawn("B", number_to_letter(i), 7);
    }



    print_board();

    cout << "knigth possible squares:  {";
    for (const auto& square : whiteknight1->possible_squares){
        cout << square.first << square.second << ", ";
    }
    cout << "}" << endl;

    cout << "bishop possible squares:  {";
    for (const auto& square : whitebishop1->possible_squares){
        cout << square.first << square.second << ", ";
    }
    cout << "}" << endl;

    cout << "rook possible squares:  {";
    for (const auto& square : whiterook1->possible_squares){
        cout << square.first << square.second << ", ";
    }
    cout << "}" << endl;

    cout << "king possible squares:  {";
    for (const auto& square : whiteking->possible_squares){
        cout << square.first << square.second << ", ";
    }
    cout << "}" << endl;

    cout << "queen possible squares:  {";
    for (const auto& square : whitequeen->possible_squares){
        cout << square.first << square.second << ", ";
    }
    cout << "}" << endl;

};
