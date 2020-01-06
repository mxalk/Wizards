//
// Created by manos on 1/6/20.
//
#pragma once

#include "classes/debug.h"
#include "Wizard.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Spell {
public:
    static vector<Spell *> spells;
    string name;
    void (*action)(Wizard& attacker, Wizard& defender);

    Spell& operator=(const Spell& s) {
#ifdef DEBUG
        cout << "NEW Spell" << " " << s.name << endl;
#endif
        this->name = s.name;
        spells.push_back(this);
        return *this;
    };
    void operator[](Spell s) {};
    Spell operator,(Spell) {return *this;};

    static void print() {
        for (const Spell s : Spell::spells)
            cout << s.name << endl;
    }
};
