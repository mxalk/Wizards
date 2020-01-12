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
    list<Round,Round> rounds;

    static Round getRound(int);





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

    static bool not_f(bool arg) { return !arg; };

    static void printall() {
        Wizard::print_wizards();
        Spell::print_spells();
    };

    static void duel() {

    }

};