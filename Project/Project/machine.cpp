#include <iostream>
#include "machine.h"
#include "board.h"
#include <ctime>
#include "game.h"

using namespace std;

const int TRIALS = 4096;    // 64 x 64

Machine::Machine(string name, Color color) : Player(name, color) {
    // randomize the seed
    srand(static_cast<unsigned int>(time(nullptr)));
}

// a sample machine that makes random but valid moves
void Machine::makeMove(Board* board) {
    for (int i = 0; i < 10 * getPieceCount(); i++) {
        int j = rand() % getPieceCount();
        Piece* p = getPiece(j);
        int y1 = p->getY();
        int x1 = p->getX();
        
        // TODO: 
        // write a loop to repeat below at most TRIALS times:
        // - generate random integers y2 and x2 in range of [0, H) and [0, W) respectively
        // - call board's move(y1, x1, y2, x2)
        // - once a valid move is returned, print the from and to cell addresses 
        //   and exit this function
        int y2, x2;
        bool moved = false;
        for (int n = 0; n < TRIALS; n++) {
            y2 = rand() % H;
            x2 = rand() % W;
            if (board->move(y1, x1, y2, x2)) {
                char c1 = x1 + 'A';
                char c2 = x2 + 'A';
                if (board->getGame()->getTurn() == WHITE) {
                    cout << "White";
                }
                else {
                    cout << "Black";
                }
                cout << "'s turn: " << c1 << y1 << " " << c2 << y2 << endl;
                moved = true;
                break;
            }
        }
        if (moved)
            break;
    }
}
