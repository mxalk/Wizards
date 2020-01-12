//
// Created by manos on 12/24/19.
//
#pragma once

#include "classes/global.h"
#include "classes/Spell.h"
#include "Action.h"
#include <vector>
#include <string>
#include <iostream>
#include <list>

using namespace std;

class Spell;
enum House { Gryffindor, Slytherin, Hufflepuff, Ravenclaw };
class Wizard {
public:
    static vector<Wizard> all_wizards;
    vector<Spell> spells;
    list<vector<Action>> rounds;
    string name, house;
    House enum_house;
    int max_hp, hp;
    bool wand;

//    void operator-=(int);
//    void operator+=(int);
    Wizard& operator=(const Wizard&);
    Wizard operator,(Wizard);
    void operator[](Wizard);
    void operator[](const string&);

    void init(const Wizard &w);
    void damage(Wizard &, int);
    void heal(Wizard &, int);
    void equip(Wizard &target, bool wand);

    void print_wizard();
    void print_wizard_name();
    void spell_select(int x);
    void print_status();

    static Wizard& getWizard(const string& name) {
        for (Wizard& w : Wizard::all_wizards) if (name == w.name) return w;
        throw exception();
    }

    static void print_wizards() {
        for (Wizard w : Wizard::all_wizards) w.print_wizard();
    }

    static void print_wizards_names() {
        for (Wizard w : Wizard::all_wizards) {
            w.print_wizard_name();
            cout << endl;
        }
    }

    static float house_modifier(House attacker_house, House defender_house) {
        float modifier = 1;

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
    bool hasWand() const;

    int getHp() const;

//    vector<Spell> & getSpell(string spell_name) ;

};
