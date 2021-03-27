#include "game.h"
#include "board.h"
#include "queen.h"


Queen::Queen(Color color, int y, int x, Board* board) : Piece(color, y, x, board) {
    setLabel(letter(QUEEN));
    setScore(QUEEN_POINTS);
}

bool Queen::isMoveValid(int y, int x) {
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
    if (abs(y - getY()) == abs(x - getX())) { // diagonal
        int moves = abs(y - getY());
        if (y < getY() && x < getX()) { // move to NW
            for (int i = 1; i < moves; i++) {
                Piece* target = board->get(getY() - i, getX() - i);
                if (target != EMPTY)
                    return false;
            }
            Piece* target = board->get(y, x); // check the target
            if (target == EMPTY || target->getColor() != this->getColor())
                return true;
        }
        if (y < getY() && x > getX()) { // move to NE
            for (int i = 1; i < moves; i++) {
                Piece* target = board->get(getY() - i, getX() + i);
                if (target != EMPTY)
                    return false;
            }
            Piece* target = board->get(y, x); // check the target
            if (target == EMPTY || target->getColor() != this->getColor())
                return true;
        }
        if (y > getY() && x < getX()) { // move to SW
            for (int i = 1; i < moves; i++) {
                Piece* target = board->get(getY() + i, getX() - i);
                if (target != EMPTY)
                    return false;
            }
            Piece* target = board->get(y, x); // check the target
            if (target == EMPTY || target->getColor() != this->getColor())
                return true;
        }
        if (y > getY() && x > getX()) { // move to SE
            for (int i = 1; i < moves; i++) {
                Piece* target = board->get(getY() + i, getX() + i);
                if (target != EMPTY)
                    return false;
            }
            Piece* target = board->get(y, x); // check the target
            if (target == EMPTY || target->getColor() != this->getColor())
                return true;
        }
    }

    return false;
}
