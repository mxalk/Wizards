//
// Created by manos on 1/10/20.
//
#pragma once


#include "Action.h"

class Action_Damage: public Action {
public:
    int amount{0};

    void apply() override {
        attacker.damage(this->defender, this->amount);
    }
};
