//
// Created by antap on 1/9/2020.
//
#pragma once

#include <iostream>
#include <vector>
#include "Wizard.h"
#include "Action_Block.h"
#include <stack>

#define TILDES std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl

using namespace std;

class Round {
public:
    vector<Action_Block> actions;
    Round &operator=(void (*)(Wizard&, Wizard&, int &round_offset, stack<int> &depth));
    void play(Wizard &attacker, Wizard &defender);
    void print_round();

};
