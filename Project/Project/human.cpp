#include <iostream>
#include "human.h"
#include "game.h"
#include "board.h"

using namespace std;

Human::Human(string name, Color color) : Player(name, color) { }

void Human::makeMove(Board* board) {
    while (true) {
        cout << this->getName() <<  "'s turn: ";
        char c1, c2;    // columns letters
        int r1, r2;     // row indexes (begin at 1)
        cin >> c1 >> r1 >> c2 >> r2;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "invalid input!" << endl;
            continue;
        }
        
        // ad hoc stop condition
        if (c1 == 'Z' && c2 == 'Z' && r1 == 0 && r2 == 0) {
            board->getGame()->setState(STOPPED);
            return;
        }
        
        // TODO:
        // Convert r1, c1 and r2, c2 into integers y1, x1, y2, x2 
        int y1 = r1 - 1;
        int x1 = toupper(c1) - 'A';
        int y2 = r2 - 1;
        int x2 = toupper(c2) - 'A';
        bool valid = board->move(y1, x1, y2, x2);
        if (valid)
            break;
        cout << "invalid input!" << endl;
    }
}
