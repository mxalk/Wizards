//
// Created by manos on 12/28/19.
//

#include "Wizard.h"

vector<Wizard> Wizard::all_wizards;

Wizard& Wizard::operator=(const Wizard& w) {
#ifdef DEBUG
    cout << "NEW WIZARD" << " " << w.name << " " << w.house << " " << w.hp << endl;
#endif
    this->name = w.name;
    this->house = w.house;
    this->hp = w.hp;
    all_wizards.push_back(*this);
    return *this;
}

void Wizard::operator[](Wizard w) {}

Wizard Wizard::operator,(Wizard) {return *this;}

Wizard& Wizard::operator=(vector<Spell *> spells) {
    for (Spell* s : spells) this->spells.push_back(s);
    return *this;
}

void Wizard::print_wizard() {
    cout << this->name << " " << this->house << " " << this->hp << endl;
    for (Spell* s : Wizard::spells)
        cout << s->name << " ";
    cout << endl;
}

void Wizard::print_wizard_name() {
    cout << this->name;
}

void Wizard::spell_select(int x) {
    cout << this->name << "(Player" << x << ") select spell" << endl;
    cout << "------------------" << endl;
    for (Spell* s : Wizard::spells) {
        cout << s->name << endl;
    }
    cout << "------------------" << endl;
}

void Wizard::print_status() {
    cout << "##################" << endl
         << "Name: " << this->name << endl
         << "Hp: " << this->hp << endl;
    if (this->wand) cout << "Wand Equipped";
    else            cout << "Wand Unequipped";
    cout << "##################" << endl << endl;
}

bool Wizard::hasWand() const {
    return wand;
}

int Wizard::getHp() const {
    return hp;
}

//vector<Spell> & Wizard::getSpell(string spell_name) {
//    for (Spell s : Wizard::spells) {
//        if (spell_name == s.name)
//            return s;
//    }
//}

}


