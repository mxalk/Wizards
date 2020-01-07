//
// Created by manos on 12/28/19.
//

#include "Wizard.h"

vector<Wizard *> Wizard::all_wizards;

//vector<Spell *> Wizard::spells;

Wizard& Wizard::operator=(const Wizard& w) {
#ifdef DEBUG
    cout << "NEW WIZARD" << " " << w.name << " " << w.house << " " << w.hp << endl;
#endif
    this->name = w.name;
    this->house = w.house;
    this->hp = w.hp;
    all_wizards.push_back(this);
    return *this;
}

void Wizard::operator[](Wizard w) {}

Wizard Wizard::operator,(Wizard) {return *this;}

void Wizard::print_wizard() {
    cout << this->name << " " << this->house << " " << this->hp << endl;
    for (const Spell* s : Wizard::spells)
        cout << s->name << " ";
    cout << endl;
}