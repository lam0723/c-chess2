#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop : public Piece
{
public:
    Bishop(Color color, int y, int x, Board* board);
    virtual bool isMoveValid(int y, int x);
};

#endif /* BISHOP_H */
