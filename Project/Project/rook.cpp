#include "game.h"
#include "board.h"
#include "rook.h"

Rook::Rook(Color color, int y, int x, Board* board) : Piece(color, y, x, board) {
    setLabel(letter(ROOK));
    setScore(ROOK_POINTS);
}

bool Rook::isMoveValid(int y, int x) {
    Board* board = getBoard();

    // check the path between target
    if (y == getY()) { // horizontal
        if (x < getX()) { // move to left
            for (int i = getX() - 1; i > x; i--) {
                Piece* target = board->get(getY(), i);
                if (target != EMPTY) return false;
            }
        }
        if (x > getX()) { // move to right
            for (int i = getX() + 1; i < x; i++) {
                Piece* target = board->get(getY(), i);
                if (target != EMPTY) return false;
            }
        }
        Piece* target = board->get(y, x); // check the target
        if (target == EMPTY || target->getColor() != this->getColor())
            return true;
    }
    if (x == getX()) { // vertical
        if (y < getY()) { // move to up
            for (int i = getY() - 1; i > y; i--) {
                Piece* target = board->get(i, getX());
                if (target != EMPTY) return false;
            }
        }
        if (y > getY()) { // move to down
            for (int i = getY() + 1; i < y; i++) {
                Piece* target = board->get(i, getX());
                if (target != EMPTY) return false;
            }
        }
        Piece* target = board->get(y, x); // check the target
        if (target == EMPTY || target->getColor() != this->getColor())
            return true;
    }

    return false;
}
