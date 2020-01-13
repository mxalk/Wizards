//
// Created by antap on 1/9/2020.
//
#pragma once

#include <iostream>
#include <vector>
#include "Wizard.h"
#include "Action_Block.h"
#include <stack>

using namespace std;

class Round {
public:
    vector<Action_Block *> actions;
    Action_Block *last_action;

    Round &operator=(void (*)(Wizard *, Wizard *));
    Round &addAction(Wizard *attacker, Wizard *defender);
    void play(Wizard *player, int phase);
    void print_round();

};
