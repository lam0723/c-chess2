#ifndef PIECE_H
#define PIECE_H

#include "board.h"
#include <string>
using std::string;

typedef string Label;

enum Color {BLACK, WHITE};

enum Piece_t {
    KING   = 'K',
    QUEEN  = 'Q',
    BISHOP = 'B',
    KNIGHT = 'N',
    ROOK   = 'R',
    PAWN   = 'P'
};

enum Score_t {
    KING_POINTS   = 1000,
    QUEEN_POINTS  = 50,
    BISHOP_POINTS = 20,
    KNIGHT_POINTS = 10,
    ROOK_POINTS   = 5,
    PAWN_POINTS   = 1
};

Label letter(Piece_t);

class Piece
{
private:
    Label label;
    Color color;
    int score;
    int y, x;
    Board* board;
protected:
    void setLabel(Label label);
    void setScore(int score);
    Board* getBoard() const;
public:
    Piece(Color color, int y, int x, Board* board);
    Label getLabel() const;
    Color getColor() const;
    int getScore() const;
    int getY() const;
    int getX() const;
    void setY(int y);
    void setX(int x);
    void capture();
    virtual bool isMoveValid(int y, int x) = 0; // abstract
    virtual void move(int y, int x);
};

#endif  /* PIECE_H */
