#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn : public Piece
{
private:
    int direction;
public:
    Pawn(Color color, int y, int x, Board* board);
    virtual bool isMoveValid(int y, int x);
    virtual void move(int y, int x);
};

#endif /* PAWN_H */
