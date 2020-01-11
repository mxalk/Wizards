//
// Created by manos on 1/6/20.
//
#pragma once

#include "classes/Wizard.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Wizard;
class Spell {
public:
    static vector<Spell> all_spells;
    string name;
    void (*action)(Wizard&, Wizard&);

    Spell& operator=(const Spell& s);
    Spell operator,(Spell);
    void operator[](Spell s);

    static Spell& getSpell(const string& name) {
        for (Spell& s : Spell::all_spells) if (name == s.name) return s;
    }
    static void print_spells() {
        for (const Spell s : Spell::all_spells)
            cout << s.name << endl;
    }
};