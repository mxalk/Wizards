//
// Created by antap on 1/9/2020.
//

#include "Round.h"

using namespace std;

void Round::print_round() {
    TILDES;
//    cout << "Round " << this->general << endl;
    TILDES;
}

Round &Round::operator=(void (*action)(Wizard *, Wizard *)) {
    if (this->last_action == nullptr) new exception();
    this->last_action->action=action;
    return *this;
}

void Round::play(Wizard *player) {
    for (Action_Block *ab: this->actions) {
        if (ab->defender != player) continue;
        ab->play();
        free(ab);
    }
}

Round &Round::addAction(Wizard *attacker, Wizard *defender) {
    Action_Block *ab = new Action_Block{attacker, defender};
    this->last_action = ab;
    this->actions.push_back(ab);
}




