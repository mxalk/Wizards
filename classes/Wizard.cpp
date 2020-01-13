//
// Created by manos on 12/28/19.
//

#include <sstream>
#include <iterator>
#include "Wizard.h"
#include <iostream>
#include <iomanip>

using namespace std;

vector<Wizard> Wizard::all_wizards;

Wizard &Wizard::operator=(const Wizard &w) {
    this->name = w.name;
    this->house = w.house;
    this->hp = w.hp;
    all_wizards.push_back(*this);
    return *this;
}

Wizard Wizard::operator,(Wizard) {return *this;}

void Wizard::operator[](Wizard) {}

void Wizard::print_wizard() const {
    cout << left << setw(25) <<this->name << setw(12) << this->house << setw(5) << right << this->hp;
    cout << "\tSpells: ";
    if (Wizard::spells.empty()) {
        cout << "None";
    } else for (Spell s : Wizard::spells)
            cout << "'" << s.name << "'" << " ";
}

void Wizard::operator[](const string& str) {
    stringstream ss(str);
    istream_iterator<string> begin(ss);
    istream_iterator<string> end;
    vector<string> vstrings(begin, end);
    for (const string& spell_name : vstrings) this->spells.push_back(Spell::getSpell(spell_name));
}

void Wizard::print_spells_choose(int x) {
    cout << this->name << "(Player" << x << ") select spell" << endl;
    cout << "-----------------------------------" << endl;
    for (const Spell &s : this->spells) cout << s.name << endl;
    cout << "-----------------------------------" << endl;
    cout << "Choose [1-" << this->spells.size() << " // Name]:";
}

void Wizard::damage(Wizard *target, int amount) {
    target->hp -= amount * Wizard::house_modifier(this->enum_house, target->enum_house);
    if (target->hp < 0) target->hp = 0;
}

int Wizard::heal(Wizard *target, int amount) {
    target->hp += amount;
    if (target->hp > target->max_hp) {
        int actual = target->hp - target->max_hp;
        target->hp = target->max_hp;
        return actual;
    }
    return amount;
}

void Wizard::equip(Wizard *target, bool wand) {
    target->wand = wand;
}

Wizard *Wizard::choose(int player_number) const {
    auto *w = new Wizard(*this);
    w->enum_house = Wizard::map(w->house);
    w->max_hp = w->hp;
    w->wand = true;
    w->player_number = player_number;
    return w;
}

void Wizard::print_status() {
    cout << "##################" << endl
         << "Name: " << this->name << endl
         << "Hp: " << this->hp << endl;
    if (this->wand) cout << "Wand Equipped";
    else            cout << "Wand Unequipped";
    cout << "##################" << endl << endl;
}

Spell *Wizard::getSpell(const string& spell_name) {
    for (Spell& s : Wizard::spells) if (spell_name == s.name) return &s;
    return nullptr;
}
Spell *Wizard::getSpell(const int &choice) {
    try {
        return &(this->spells.at(choice));
    } catch (const exception &e) {}
    return nullptr;
}

void Wizard::ravenclaw_check() {
    if (this->enum_house != Ravenclaw || game_round%2 == 1) return;
    int i = this->max_hp * 0.05;
    i = this->heal(this, i);
    cout << "Wizard of House Ravenclaw heals self for " << i << " HP" << endl;
}
