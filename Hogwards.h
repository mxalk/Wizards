//
// Created by manos on 12/24/19.
//
#pragma once

#include "classes/Wizard.h"
#include "classes/Spell.h"
#include "classes/Game.h"
#include "classes/Action_Damage.h"
#include <iostream>
#include <stack>

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
#define ACTION .action = (false)?[](Wizard& attacker, Wizard& defender){}
#define START [](Wizard& attacker, Wizard& defender) {\
    stack <int> depth;\
    depth.push(0);\
    int round_offset = 0;
#define END ;round_offset = depth.top(); depth.pop(); }
//#define α "
//#define _ "

#define ATTACKER attacker
#define DEFENDER defender

#define DAMAGE ;
#define HEAL ;
#define EQUIP ;

#define GET_HP(wizard) wizard.hp
#define GET_HOUSE(wizard) wizard.house
#define GET_NAME(wizard) wizard.name
#define HAS_WAND(wizard) wizard.wand

#define AND Game::and_f
#define OR Game::or_f
#define NOT Game::not_f

#define IF ;depth.push(round_offset); if (
#define ELSE_IF ;round_offset = depth.top(); depth.pop(); }; else if (
#define ELSE ;round_offset = depth.top(); depth.pop(); }; else {
#define DO ) Game::getRound(round_offset) = [](Wizard& attacker, Wizard& defender, int &round_offset, stack<int> &depth) {

#define FOR ;depth.push(round_offset); for (round_offset=0; round_offset<
#define ROUNDS ; round_offset++
#define AFTER ;depth.push(round_offset); if (round_offset=

#define SHOW cout<<


// SPELL LEARNING

#define MR ;Wizard::getWizard(
#define MRS ;Wizard::getWizard(
#define LEARN )
#define SPELL_NAME(X) #X" "