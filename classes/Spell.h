//
// Created by manos on 1/6/20.
//
#pragma once

#include "classes/debug.h"
#include "classes/Wizard.h"
#include <vector>
#include <string>
#include <iostream>
#include <functional>

using namespace std;

class Wizard;
class Spell {
public:
    static vector<Spell *> all_spells;
    string name;
    void (*action)(Wizard&, Wizard&);

    Spell& operator=(const Spell& s);
    void operator[](Spell s);
    Spell operator,(Spell);

    static void print() {
        for (const Spell* s : Spell::all_spells)
            cout << s->name << endl;
    }
};
