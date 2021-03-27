#include <iostream>
#include "game.h"
#include "human.h"
#include "machine.h"

using namespace std;

Game::Game(Mode mode) : state(RUNNING) {
    if (mode == Human_vs_Human) {
        black = new Human("Black", BLACK);
        white = new Human("White", WHITE);
    } else if (mode == Human_vs_Machine) {
        black = new Machine("Black", BLACK);
        white = new Human("White", WHITE);
    } else {
        black = new Machine("Black", BLACK);
        white = new Machine("White", WHITE);
    }
    
    turn = WHITE;       // convention is white first
    state = RUNNING;    // start the game
    
    // board construction will add pieces to players' piece vectors
    // so the board must be constructed after players
    board = new Board(this);
}

Color Game::getTurn() const {
    return turn;
}

State Game::getState() const {
    return state;
}

void Game::setState(State state) {
    this->state = state;
}

Player* Game::getBlack() const {
    return black;
}

Player* Game::getWhite() const {
    return white;
}

void Game::run() {
    for (int round = 1; state == RUNNING ; round++)  {
        cout << "Round " << round << ":" << endl;
        
        // print game board
        board->print();
        
        // move a chess piece
        if (turn == WHITE)
            white->makeMove(board);
        else
            black->makeMove(board);
        
        // flip turns
        turn = (turn == WHITE) ? BLACK : WHITE;
    }
    
    // compute scores to see who wins
    int black_score = 0, white_score = 0;

    // TODO:
    // compute black_score and white_score by summing
    // the scores of pieces in the list kept by each player 
    for (int i = 0; i < black->getPieceCount(); i++) {
        black_score += black->getPiece(i)->getScore();
    }
    for (int i = 0; i < white->getPieceCount(); i++) {
        white_score += white->getPiece(i)->getScore();
    }

    if (black_score > white_score)
        cout << "Black wins!" << endl;
    else if (white_score > black_score)
        cout << "White wins!" << endl;
    else
        cout << "Draw game!" << endl;
}
