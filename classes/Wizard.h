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

class Spell;
class Wizard {
public:
    static vector<Wizard> all_wizards;
    vector<Spell *> spells;
    string name, house;
    int hp;
    bool wand = true;

    Wizard& operator=(const Wizard&);
    void operator[](Wizard w);
    Wizard operator,(Wizard);
    Wizard& operator=(vector<Spell *> spells);

    void print_wizard();
    void print_wizard_name();
    //void spell_select();

    static Wizard& getWizard(string name) {
        for (Wizard& w : Wizard::all_wizards) if (name == w.name) return w;
    }

    static void print_wizards() {
        for (Wizard w : Wizard::all_wizards) w.print_wizard();
    }

    static void print_wizards_names() {
        for (Wizard w : Wizard::all_wizards) w.print_wizard_name();
    }

};
