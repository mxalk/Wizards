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

Round &Round::operator=(void (*action)(Wizard &, Wizard &, int &round_offset, stack<int> &depth)) {
    this->actions.emplace_back(action);
    return *this;
}

void Round::play(Wizard &attacker, Wizard &defender) {
    stack <int> depth;
    depth.push(0);
    int round_offset = 0;

    for (Action_Block &ab: this->actions)
        ab.play(attacker, defender, round_offset, depth);
//    CHOOSE SPELL
    for (Action_Block &ab: this->actions)
        ab.play(attacker, defender, round_offset, depth);
}




