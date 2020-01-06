//
// Created by manos on 12/24/19.
//
#pragma once

#include "classes/debug.h"
#include "classes/Wizard.h"
#include "classes/Spell.h"

#define BEGIN_GAME int main() {Wizard tmpw; Spell tmps;
#define END_GAME return 0;}
#define CREATE ;
#define DUEL duel();


// WIZARDS

#define WIZARD tmpw = Wizard
#define WIZARDS Wizard {}

#define NAME .name = (false)?""
#define HOUSE .house = (false)?""
#define HP .hp = (false)?0

// SPELLS

#define SPELL tmps = Spell
#define SPELLS Spell {}
#define ACTION .action = (false)?[](){}
#define START []() {
#define END }