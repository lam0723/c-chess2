#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

class Queen : public Piece
{
public:
    Queen(Color color, int y, int x, Board* board);
    virtual bool isMoveValid(int y, int x);
};

#endif /* QUEEN_H */
