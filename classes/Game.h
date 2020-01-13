//
// Created by manos on 1/6/20.
//
#pragma once

#include "classes/Wizard.h"
#include "classes/Spell.h"
#include "global.h"
#include "Round.h"
#include <list>
#include <string>
#include <cstdarg>
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

class Wizard;
class Spell;
class Game {
public:
    static list<Round> rounds;

    static Round &getRound(int r) {
       while (r > Game::rounds.size()) Game::rounds.push_back(Round{});
       auto it = rounds.begin();
       std::advance(it, r);
       return *it;
    }

//    static int get_hp(Wizard &w) { return w.hp; };
//    static string get_house(Wizard &w) { return w.house; }
//    static string get_name(Wizard &w) { return w.name; }
//    static bool has_wand(Wizard &w) { return w.wand; }

    template <typename Arg>
    static bool and_func(Arg arg1, Arg arg2) {return arg1 && arg2;}

    template <typename Firsts, typename... The>
    static bool and_func(Firsts arg1, Firsts arg2, The... rest) {
            bool tmp = arg1 && arg2;
            and_func(arg1,arg2);
            return and_func(tmp, rest...);
    }

    template <typename Arg>
    static bool or_func(Arg arg1, Arg arg2) {return arg1 || arg2;}

    template <typename Firsts, typename... The>
    static bool or_func(Firsts arg1, Firsts arg2, The... rest) {
            bool tmp = arg1 || arg2;
            or_func(arg1,arg2);
            return or_func(tmp, rest...);
    }


    static bool not_f(bool arg) { return !arg; };

    static void printall() {
        Wizard::print_wizards();
        Spell::print_spells();
    };

    static bool choose_ok(int choice, int max) {
        return (choice < 1 || choice > max);
    }
    static bool choose_ok(int choice, int min, int max) {
        return (choice < min || choice > max);
    }

    static void duel() {
        int p, wizards_size_choose = Wizard::all_wizards.size(), players, tmp;
        bool invalid_choice;

        cout << "----------------------------------- HARRY POTTER THE GAME -----------------------------------" << endl << endl;

        do {
            cout << "Enter # of Players[2-6]:" << endl;
            cin >> players;
            invalid_choice = choose_ok(players, 2, 6);
            if (invalid_choice) cout << endl << R"(!INVALID CHOICE!!)" << endl;
        } while (invalid_choice);

        Wizard *wizards[players];

        for (tmp = 0; tmp<players; tmp++) {
            do {
                cout << "Player "<< tmp+1 << " selects wizard:" << endl
                     << "--------------------------" << endl;
                Wizard::print_wizards();
                cout << "--------------------------" << endl;
                cout << "Choose [1-" << wizards_size_choose << "]:";
                cin >> p;
                invalid_choice = choose_ok(p, wizards_size_choose);
                if (invalid_choice) cout << endl << R"(!INVALID CHOICE!!)" << endl;
            } while (invalid_choice);
            wizards[tmp] = Wizard::all_wizards.at(p-1).choose();
            cout << "Player "<< tmp+1 << " selected wizard: " << wizards[tmp]->name <<endl;
            cout << endl;
        }

        Wizard * w1 = wizards[0];
        Wizard * w2 = wizards[1];

        while ( w1->hp > 0 && w2->hp > 0) {
            PRINT_ROUND(game_round);
            if (w1->wand) {
                Spell sp1;      string str1;
                w1->spell_select(1);
                getline (std::cin, str1);
                sp1 = w1->Wizard::getSpell(str1);
                // spell action
                w1->print_status();
                w2->print_status();
            } else {
                cout << w1->name << "(Player1) has no wand equipped, can't cast spell." << endl;
            }

            if(w2->wand) {
                Spell sp2;      string str2;
                w2->spell_select(2);
                getline (std::cin, str2);
                sp2 = w2->Wizard::getSpell(str2);
                // spell action
                w1->print_status();
                w2->print_status();
            } else {
                cout << w2->name << "(Player2) has no wand equipped, can't cast spell." << endl;
            }

            ++game_round;
        }
    }
};

// anti gia    while ( w1->hp > 0 && w2->hp > 0)
// vale auto   while (count < players - 1)

// sto telos tis while:

//        int count = 0;
//        Wizard * winner;
//        for (int i = 0; i < players; ++i) {
//            if (wizards[i]->hp <= 0)
//                count++;
//            winner = wizards[i];
//        }

// e3o apo ti while:

//        if (count < players) {
//            cout << "AND THE WINNER IS  " << winner->name; << " !!!" << endl;
//        } else {
//            cout << "THEY ARE ALL DEAD" << endl;
//        }
