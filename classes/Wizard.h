//
// Created by manos on 12/24/19.
//
#pragma once

#include "classes/global.h"
#include "classes/Spell.h"
#include "classes/Wand.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Spell;
enum House { Gryffindor, Slytherin, Hufflepuff, Ravenclaw };
class Wizard {
public:
    static vector<Wizard> all_wizards;
    vector<Spell> spells;
    string name, house;
    House enum_house;
    int max_hp, hp, player_number, action_amount;
    bool wand, wand_to_have;

    Wizard *operator=(int amount);
    Wizard *operator=(Wand w);
    Wizard &operator=(const Wizard &w);
    Wizard operator,(Wizard);
    void operator[](Wizard);
    void operator[](const string&);

    Wizard *choose(int player_number) const;
    int damage(Wizard *, int);
    int heal(Wizard *, int);
    void equip(Wizard *target, bool wand);
    void ravenclaw_heal();

    void print_wizard() const;
    void print_spells_choose();
    void print_status();

    Spell *getSpell(const string &spell_name);
    Spell *getSpell(const int &choice);

    static Wizard& getWizard(const string& name) {
        for (Wizard& w : Wizard::all_wizards) {
            if (name == w.name) return w;
        }
        throw exception();
    }

    static void print_wizards() {
        int i = 1;
        for (Wizard w : Wizard::all_wizards) {
            cout << i++ << ". ";
            w.print_wizard();
            cout << endl;
        }
    }

    static float house_modifier(House attacker_house, House defender_house) {
        float modifier = 1.0;

        switch(attacker_house) {
            case Gryffindor:
                break;
            case Slytherin:
                modifier += 0.15;
                if (defender_house == Gryffindor) modifier += 0.05;
                break;
            case Hufflepuff:
                modifier += 0.07;
                break;
            case Ravenclaw:
                if (game_round%2 == 1) modifier += 0.07;
                break;
        }

        switch(defender_house) {
            case Gryffindor:
                modifier -= 0.2;
                if (attacker_house == Slytherin) modifier -= 0.1;
                break;
            case Slytherin:
                break;
            case Hufflepuff:
                modifier -= 0.07;
                break;
            case Ravenclaw:
                break;
        }
        return modifier;
    }

    static House map(string house) {
        if (house == "Gryffindor") return Gryffindor;
        if (house == "Slytherin") return Slytherin;
        if (house == "Hufflepuff") return Hufflepuff;
        if (house == "Ravenclaw") return Ravenclaw;
        throw exception();
    }

};
