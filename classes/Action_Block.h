//
// Created by manos on 1/12/20.
//
#pragma once


#include <stack>
#include "Wizard.h"

class Action_Block {
public:
    int rounds_total, rounds_remaining;
    Wizard *attacker, *defender;
    void (*action)(Wizard *attacker, Wizard *defender){};
//    Spell &origin;
//    explicit Action_Block(void (*action)(Wizard &, Wizard &, int &round_offset, stack<int> &depth))
//            : action(action) {};

    Action_Block(Wizard *attacker, Wizard *defender, int rounds_total)
            : attacker(attacker), defender(defender), rounds_total(rounds_total) {
        this->action = nullptr;
        this->rounds_remaining = this->rounds_total;
    };

    Action_Block &operator=(void (*action)(Wizard *, Wizard *)) {
        this->action = action;
    }

    void play() {
        this->action(attacker, defender);
    }
};
