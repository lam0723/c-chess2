#ifndef KING_H
#define KING_H

#include "piece.h"

class King : public Piece
{
public:
    King(Color color, int y, int x, Board* board);
    virtual bool isMoveValid(int y, int x);
};

#endif /* KING_H */
