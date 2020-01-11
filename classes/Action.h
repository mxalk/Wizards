//
// Created by manos on 1/10/20.
//
#pragma once

#include "Wizard.h"

class Action {
public:
    Wizard attacker;
    Wizard defender;

    virtual void apply() = 0;

    void setAttacker(Wizard &w) {
        this->attacker = w;
    };
    void setDefender(Wizard &w) {
        this->defender = w;
    };
};

//void Action::setAttacker(Wizard &w)
//void Action::setDefender(Wizard &w)
