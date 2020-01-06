//
// Created by manos on 12/24/19.
//
#pragma once

#include "classes/debug.h"
#include <initializer_list>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Wizard {
public:
    static vector<Wizard> wizards;
    string name, house;
    int hp;

//    Wizard(){string, string, int};

//    Wizard(std::initializer_list<>){};

    Wizard& operator=(const Wizard& w) {
#ifdef DEBUG
        cout << "NEW WIZARD" << " " << w.name << " " << w.house << " " << w.hp << "\n";
#endif
        this->name = w.name;
        this->house = w.house;
        this->hp = w.hp;
        wizards.push_back(*this);
        return *this;
    };
    void operator[](Wizard w) {};
    Wizard operator,(Wizard) {return *this;};

    static void print() {
        for (const Wizard w : Wizard::wizards)
            cout << w.name << " " << w.house << " " << w.hp << "\n";
    }
};
