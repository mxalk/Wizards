//
// Created by manos on 1/12/20.
//
#pragma once


#include <stack>
#include "Wizard.h"

class Action_Block {
public:
    Wizard *attacker, *defender;
    void (*action)(Wizard *attacker, Wizard *defender){};
//    Spell &origin;
//    explicit Action_Block(void (*action)(Wizard &, Wizard &, int &round_offset, stack<int> &depth))
//            : action(action) {};

    Action_Block(Wizard *attacker, Wizard *defender)
            : attacker(attacker), defender(defender) {
        this->action = nullptr;
    };

    void play() {
        this->action(attacker, defender);
    }
};
