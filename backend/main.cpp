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

    //build json client board
    crow::json::wvalue client_board = crow::json::wvalue::list();
    for (int i = 0; i< 8; i++){
        crow::json::wvalue row = crow::json::wvalue::list();
        for (int j = 0; j < 8; j++){
            if (board[i][j] == nullptr){
                row[row.size()] = "Empty";
            }
            else{
            ostringstream os;
            os << *board[i][j];
            row[row.size()] = os.str();
            }
        }
        client_board[client_board.size()] = move(row);
    }

    CROW_ROUTE(app, "/board")([client_board](){

        return client_board;
    });

    app.port(18080).multithreaded().run();

};
