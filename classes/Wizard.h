//
// Created by manos on 12/24/19.
//
#pragma once

#include "classes/debug.h"
#include "classes/Spell.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Wizard {
public:
    static vector<Wizard *> all_wizards;
    vector<Spell *> spells;
    string name, house;
    int hp;
    bool wand = true;

    Wizard& operator=(const Wizard& w);
    void operator[](Wizard w);
    Wizard operator,(Wizard);

    void print_wizard();

    static void print_wizards() {
        for (Wizard* w : Wizard::all_wizards) w->print_wizard();
    }
};
