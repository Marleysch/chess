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

    Piece * whiterook1 = new Rook("W", 'a', 1);
    Piece * whiteknight1 = new Knight("W", 'b', 1);
    Piece * whitebishop1 = new Bishop("W", 'c', 1);
    Piece * whiteking = new King("W", 'e', 1);
    Piece * whitequeen = new Queen("W", 'd', 1);
    Piece * whitepawn = new Pawn("W", 'g', 2);
    Piece * blackknight = new Knight("B", 'h', 3);
    Piece * blackpawn = new Pawn("B", 'g', 7);
    Piece * whiteknight = new Knight("W", 'h', 6);

    print_board();
    whiteknight1->move({'d',2});
    print_board();
    whitebishop1->move({'b',2});
    print_board();
    whiteking->move({'c',1});
    print_board();
    blackpawn->move({'h',6});
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

    print_board();

    cout << "queen possible squares:  {";
    for (const auto& square : whitequeen->possible_squares){
        cout << square.first << square.second << ", ";
    }
    cout << "}" << endl;

    cout << " white pawn possible squares:  {";
    for (const auto& square : whitepawn->possible_squares){
        cout << square.first << square.second << ", ";
    }
    cout << "}" << endl;

    cout << "black pawn possible squares:  {";
    for (const auto& square : blackpawn->possible_squares){
        cout << square.first << square.second << ", ";
    }
    cout << "}" << endl;

};
