#include <iostream>
#include "game.h"
#include "board.h"
#include "piece.h"

using namespace std;

Label letter(Piece_t type) {
    return string(1, type);
}

Piece::Piece(Color color, int y, int x, Board* board) {
    this->color = color;
    this->y = y;
    this->x = x;
    this->board = board;
}

void Piece::setLabel(Label label){
    this->label = label;
}

Label Piece::getLabel() const {
    return label;
}

Color Piece::getColor() const {
    return color;
}

void Piece::setScore(int score){
    this->score = score;
}

int Piece::getScore() const {
    return score;
}

int Piece::getY() const {
    return y;
}

int Piece::getX() const {
    return x;
}

Board* Piece::getBoard() const {
    return board;
}

void Piece::setY(int y) {
    this->y = y;
}

void Piece::setX(int x) {
    this->x = x;
}

void Piece::capture() {
    // Remove the piece of the player's list of pieces
    Game* g = board->getGame();
    Player* p = (color == BLACK) ? g->getBlack() : g->getWhite();
    p->delPiece(this);
    
    // check winning condition
    if (this->getLabel() == letter(KING))
        board->getGame()->setState(STOPPED);
}

void Piece::move(int y, int x) {
    Board* board = getBoard();

    // TODO:
    // capture opponent piece
    // hint: get the piece at (y, x)
    // call capture() on the piece if it is of different color from mine
    Piece* target = board->get(y, x);
    if (target != EMPTY) {
        if (color != target->getColor())
            target->capture();
    }
    // carry out the move
    board->put(getY(), getX(), EMPTY);
    board->put(y, x, this);
}
