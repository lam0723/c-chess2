#include "game.h"
#include "board.h"
#include "king.h"

const int DY[] = {-1, -1,  0,  1,  1,  1,  0, -1};
const int DX[] = { 0,  1,  1,  1,  0, -1, -1, -1};
                // N  NE   E  SE   S  SW   W  NW

King::King(Color color, int y, int x, Board* board) : Piece(color, y, x, board) {
    setLabel(letter(KING));
    setScore(KING_POINTS);
}

bool King::isMoveValid(int y, int x) {
    Board* board = getBoard();
    for (int d = 0; d < 8; d++) {
        if (y == getY() + DY[d] && x == getX() + DX[d]) {
            Piece* target = board->get(getY() + DY[d], getX() + DX[d]);
            // move to an empty cell or capture opponent piece
            if (target == EMPTY || target->getColor() != this->getColor())
                return true;
        }
    }
    return false;
}
