#include "board.h"
#include "pawn.h"
#include <iostream>

using namespace std;

Pawn::Pawn(Color color, int y, int x, Board* board) : Piece(color, y, x, board) {
    setLabel(letter(PAWN));
    setScore(PAWN_POINTS);
    direction = (color == BLACK) ? 2 : -2;
}

bool Pawn::isMoveValid(int y, int x) {
    Board* board = getBoard();
    Piece* p = board->get(y, x);
    int dy = y - getY();
    int dx = x - getX();
    
    int delta = direction;
    if (direction > 1)  delta = direction - 1;
    if (direction < -1) delta = direction + 1;
    
    if (dy == delta) {  // one cell forward
        if (abs(dx) == 1 && p != EMPTY &&
            p->getColor() != this->getColor())  // killing diagonally
            return true;
        if (dx == 0 && p == EMPTY)  // no piece ahead
            return true;
    }
    if (dy == direction && dx == 0 && p == EMPTY &&
        board->get(getY() + delta, getX()) == EMPTY)    // no piece blocking the way
        return true;
    return false;
}

void Pawn::move(int y, int x) {
    Piece::move(y, x);
    // after first move, pawns can move one step instead of two
    direction = (getColor() == BLACK) ? 1 : -1;
}
