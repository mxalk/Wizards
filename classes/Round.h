//
// Created by antap on 1/9/2020.
//
#pragma once

#include <iostream>
#include <vector>
#include "Wizard.h"

#define TILDES std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl

using namespace std;

class Round {
public:
    vector<void (*)(Wizard& attacker, Wizard& defender)> actions;
    Round& operator=(void (*)(Wizard& attacker, Wizard& defender));
    void play();



    void test() {
        Round r;
        r = [](Wizard& attacker, Wizard& defender) {
            cout << "LALALA";
        };
    }

    void print_round();
};
