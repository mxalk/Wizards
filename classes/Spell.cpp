//
// Created by manos on 1/6/20.
//

#include "Spell.h"

vector<Spell *> Spell::all_spells;


Spell& Spell::operator=(const Spell& s) {
#ifdef DEBUG
    cout << "NEW Spell" << " " << s.name << endl;
#endif
    this->name = s.name;
    this->action = s.action;
    all_spells.push_back(this);
    return *this;
};
void Spell::operator[](Spell s) {};
Spell Spell::operator,(Spell) {return *this;}

//Spell::Spell(string name, void (*action)(Wizard &, Wizard &)) {
//    this->name = name;
//    this->action = action;
//    Spell::all_spells.push_back(this);
//};
