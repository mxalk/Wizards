//
// Created by manos on 1/12/20.
//
#pragma once


#include <stack>
#include "Wizard.h"

class Action_Block {
public:
    void (*action)(Wizard &attacker, Wizard &defender, int &round_offset, stack<int> &depth);
//    Spell &origin;
    explicit Action_Block(void (*action)(Wizard &, Wizard &, int &round_offset, stack<int> &depth))
            : action(action) {};
    void play(Wizard &attacker,Wizard &defender, int &round_offset, stack<int> &depth) {
        this->action(attacker, defender, round_offset, depth);
    }
};
