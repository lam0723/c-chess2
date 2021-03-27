#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class Knight : public Piece
{
public:
    Knight(Color color, int y, int x, Board* board);
    virtual bool isMoveValid(int y, int x);
};

#endif /* KNIGHT_H */
