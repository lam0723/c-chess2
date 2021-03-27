#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "player.h"

enum Mode { Human_vs_Human = 1, Human_vs_Machine, Machine_vs_Machine};

enum State { RUNNING, STOPPED };

class Game
{
private:
    Board* board;
    Player* white;
    Player* black;
    Color turn;
    State state;
public:
    Game(Mode mode);
    void run();
    Board* getBoard() const;
    Player* getWhite() const;
    Player* getBlack() const;
    Color getTurn() const;
    State getState() const;
    void setState(State state);
};

#endif /* GAME_H */
