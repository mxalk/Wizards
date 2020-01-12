//
// Created by antap on 1/9/2020.
//

#include "Round.h"

using namespace std;

void Round::print_round() {
    TILDES;
    cout << "Round " << this->general << endl;
    TILDES;
}

Round &Round::operator=(void (*action)(Wizard &, Wizard &)) {
    this->actions.push_back(action);
}

void Round::play() {
    for (void (*action)(Wizard& attacker, Wizard& defender): this->actions)
        action(attacker, defender);
//    CHOOSE SPELL
    for (void (*action)(Wizard& attacker, Wizard& defender): this->actions)
        action(attacker, defender);
}




