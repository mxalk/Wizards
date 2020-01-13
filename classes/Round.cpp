//
// Created by antap on 1/9/2020.
//

#include "Round.h"

using namespace std;

Round &Round::operator=(void (*action)(Wizard *, Wizard *)) {
    if (this->last_action == nullptr) new exception();
    this->last_action->action=action;
    return *this;
}

void Round::play(Wizard *player, int phase) {
    Action_Block *block;
    bool replay;
    do {
        replay = false;
        for (auto it = this->actions.begin(); it != this->actions.end();) {
            block = *it;
            if ((phase==1 && block->defender != player) || (phase == 2 && block->defender != player && block->attacker != player)) {
                it++;
                continue;
            }
            block->play();
            this->actions.erase(it);
            free(block);
            replay = true;
        }
    } while (replay);
}

Round &Round::addAction(Wizard *attacker, Wizard *defender) {
    Action_Block *ab = new Action_Block{attacker, defender};
    cout << "HERE" << endl;
    this->last_action = ab;
    cout << "HERE1" << endl;
    this->actions.push_back(ab);
    cout << "HERE2" << endl;
    return *this;
}
