#include "game.h"
#include "board.h"
#include "knight.h"

const int DY[] = { -1, -2, -2, -1,  1,  2,  2,  1 };
const int DX[] = { -2, -1,  1,  2,  2,  1, -1, -2 };


Knight::Knight(Color color, int y, int x, Board* board) : Piece(color, y, x, board) {
    setLabel(letter(KNIGHT));
    setScore(KNIGHT_POINTS);
}

bool Knight::isMoveValid(int y, int x) {
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
