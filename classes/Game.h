//
// Created by manos on 1/6/20.
//
#pragma once

#include "classes/Wizard.h";
#include <stdarg.h>

class Game {
public:
    static int get_hp(Wizard w) { return w.hp; };
    static string get_house(Wizard w) { return w.house; }
    static string get_name(Wizard w) { return w.name; }
    static bool has_wand(Wizard w) { return w.wand; }

    static bool and_f(bool arg1, bool arg2, bool...) {
        bool tmp = true;
        if (!arg1 || !arg2) return false;
        va_list vl;
        va_start(vl,tmp);
        while (tmp) {
            if (!tmp) return false;
            tmp=va_arg(vl, bool);
        }
        va_end(vl);
        return true;
    };
    static bool or_f(bool arg1, bool arg2, bool...) {};
    static bool not_f(bool arg) { return !arg; };
};
