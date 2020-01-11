//
// Created by manos on 1/6/20.
//

#include "Spell.h"

vector<Spell> Spell::all_spells;


Spell& Spell::operator=(const Spell& s) {
    this->name = s.name;
    this->action = s.action;
    all_spells.push_back(*this);
    return *this;
};
Spell Spell::operator,(Spell) {return *this;}
void Spell::operator[](Spell s) {};
