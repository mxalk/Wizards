//
// Created by antap on 1/9/2020.
//

#include "Round.h"

using namespace std;

void Round::play(Wizard *player, int phase) {
    Action_Block *block;
    bool replay;

    do {
        replay = false;
        cout << "--------------------------------  "<< this->actions.size() << endl;
        for (auto it = this->actions.begin(); it != this->actions.end();) {
            block = *it;
            cout << "--------------------------------BLOCK MIGHT BE EXECUTED" << endl;
            if ((phase==1 && block->defender != player) || (phase == 2 && block->defender != player && block->attacker != player)) {
                it++;
                continue;
            }
            cout << "--------------------------------BLOCK IS BEING EXECUTED" << endl;
            block->play();
            this->actions.erase(it);
            free(block);
            replay = true;
        }
    } while (replay);
}

Action_Block &Round::addAction(Wizard *attacker, Wizard *defender) {
    Action_Block *ab = new Action_Block(attacker, defender);
    this->actions.push_back(ab);
    return *ab;
}

Round::Round() = default;
