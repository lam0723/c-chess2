#ifndef BOARD_H
#define BOARD_H

class Game;     // forward declaration
class Piece;    // (to resolve cyclic dependencies)

Piece* const EMPTY = nullptr;
Piece* const OUT_BOUND = (Piece*) new int;
const int H = 8; // board height
const int W = 8; // board width

class Board
{
private:
    Piece* cells[H][W];
    Game* game; // back link to the game
public:
    Board(Game* game);
    void configure();
    bool isEmpty(int y, int x);
    Piece* get(int y, int x);
    void put(int y, int x, Piece* p);
    bool move(int y1, int x1, int y2, int x2);
    void print();
    Game* getGame() const;
};

#endif
