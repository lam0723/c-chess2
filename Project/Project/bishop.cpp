#include "game.h"
#include "board.h"
#include "bishop.h"

Bishop::Bishop(Color color, int y, int x, Board* board) : Piece(color, y, x, board) {
    setLabel(letter(BISHOP));
    setScore(BISHOP_POINTS);
}

bool Bishop::isMoveValid(int y, int x) {
    Board* board = getBoard();
   
    if (y == getY() || x == getX()) // move horizontal or vertical
        return false;
    if (abs(y - getY()) != abs(x - getX())) // check diagonal
        return false;

    // check along the path between target
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

    return false;
}
