//
// Created by manos on 1/6/20.
//
#pragma once

#include "classes/Wizard.h"
#include "classes/Spell.h"
#include "Round.h"
#include <list>
#include <string>
#include <cstdarg>

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

    /*
     * an sinexizei na prospa8ei na diavazei arguments
     * akoma ki an den uparxoun, tote yparxei provlima.
     * Pou isos na linete me kapoio try catch.
     * Allios an iparxei kapoios tropos na ta metrame,
     * px gia ka8e comma pou vriskei +1 argument kai na valoume
     * auton ton counter san proto orisma stin sinartisi as poume
     *
     * an den ginete tpt apo auta, mporoume na to afisoume
     * to "toulaxiston 2" kai na pai3oume me "akrivos 2" orismata
     * gia tin ora, kai to koitame argotera mipos skeftoume
     * kalitero tropo
     * */

    // old ones
/*
    static bool and_f(bool arg1, bool arg2...) {
        if (!arg1 || !arg2) return false;
        va_list vl;
        va_start(vl,arg2);
        bool tmp = true;
        while(tmp) {
            tmp = va_arg(vl, bool);
        }
        va_end(vl);
        return tmp;
    };

    static bool or_f(bool arg1, bool arg2, bool...) {
        if (arg1 || arg2) return true;
        va_list vl;
        va_start(vl,arg2);
        bool tmp = false;
        while(!tmp) {
            tmp = va_arg(vl, bool);
        }
        va_end(vl);
        return tmp;
    };
*/

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

    static void duel() {

        std::string str1;
        std::string str2;

        cout << "-------------------------HARRY POTTER THE GAME------------------------" << endl << endl;
        cout << "Player1 select wizard:" << endl
             << "------------------" << endl;
        Wizard::print_wizards_names();
        cout << "------------------" << endl;
        getline (std::cin, str1);

        cout << "Player2 select wizard:" << endl
             << "------------------" << endl;
        Wizard::print_wizards_names();
        cout << "------------------" << endl;
        getline (std::cin, str2);

        Wizard w1 = Wizard::getWizard(str1);
        Wizard w2;

        if (str1 == str2) {
            // need a copy of wizard 1
        } else {
            w2 = Wizard::getWizard(str2);
        }

        Round round;
        while ( w1.getHp() > 0 && w2.getHp() > 0) {
            round.print_round();

            if (w1.hasWand()) {
                Spell sp1;      string s1;
                w1.spell_select(1);
                getline (std::cin, s1);
                //sp1 = Wizard::getSpell(s1);   implement getSpell, lookup sto vector_spell tou wiz
                w1.print_status();
                w2.print_status();
            } else {
                w1.print_wizard_name();
                cout << "(Player1) has no wand equipped, can't cast spell." << endl;
            }

            if(w2.hasWand()) {
                Spell sp2;      string s2;
                w2.spell_select(2);
                getline (std::cin, s2);
                //sp2 = Wizard::getSpell(s2);
                w1.print_status();
                w2.print_status();
            } else {
                w2.print_wizard_name();
                cout << "(Player2) has no wand equipped, can't cast spell." << endl;
            }

            // round++ na kano overload to increment
        }
    }
};