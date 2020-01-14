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

void Wizard::print_spells_choose() {
    int i = 1;
    cout << "Player " << this->player_number << " (" << this->name << ") selects spell" << endl;
    cout << "---------------------------------------------------------------------------------" << endl;
    cout << "|| ";
    for (const Spell &s : this->spells) cout << i++ << ". " << s.name << " || ";
    cout << endl;
    cout << "---------------------------------------------------------------------------------" << endl;
    cout << "Choose [1-" << this->spells.size() << " // Name]:";
}

int Wizard::damage(Wizard *target, int amount) {
    int actual = Wizard::house_modifier(this->enum_house, target->enum_house) * amount;
    target->hp -= actual;
    if (target->hp < 0) target->hp = 0;
    return actual;
}

int Wizard::heal(Wizard *target, int amount) {
    target->hp += amount;
    if (target->hp > target->max_hp) {
        int actual = amount - (target->hp - target->max_hp);
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
#define HP_WIDTH 20
void Wizard::print_status() {
    string tmp = "";
    for (int i=0; i<HP_WIDTH*this->hp/this->max_hp; i++) tmp += '#';
    for (int i=0; i<HP_WIDTH-HP_WIDTH*this->hp/this->max_hp; i++) tmp += ' ';
    cout <<        "***************************" << endl
         << "Player: " << this->player_number << endl
         << "Name: " << this->name << endl
         << "[ " << tmp << " ]" << endl;
    cout << "Hp: " << this->hp << "/" << this->max_hp << endl;
    if (this->wand) cout << "-----@";
    else            cout << "-----X";
    cout << endl << "***************************" << endl;
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

void Wizard::ravenclaw_heal() {
    if (this->enum_house != Ravenclaw || game_round%2 == 1) return;
    int i = this->max_hp * 0.05;
    i = this->heal(this, i);
    if(i==this->max_hp)  cout << "Wizard of House Ravenclaw has full health, heal skipped";
    else                 cout << "Wizard of House Ravenclaw heals self for " << i << " HP";
    cout << endl;
}

Wizard *Wizard::operator=(int amount) {
    this->action_amount = amount;
    return this;
}

Wizard *Wizard::operator=(Wand w) {
    this->wand_to_have = w.wand;
    return this;
}
