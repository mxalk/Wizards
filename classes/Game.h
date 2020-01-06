//
// Created by manos on 1/6/20.
//
#pragma once

#include "classes/Wizard.h";

class Game {
public:
    static int get_hp(Wizard w){ return w.hp; };
    static string get_house(Wizard w) { return w.house; }
    static string get_name(Wizard w) { return w.name; }
    static bool has_wand(Wizard w) { return w.wand; }
};
