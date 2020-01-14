//
// Created by manos on 12/24/19.
//
#pragma once

#include "classes/Wizard.h"
#include "classes/Spell.h"
#include "classes/Game.h"
#include "classes/Action.h"
#include <iostream>
#include <stack>

#define BEGIN_GAME int main() {Wizard tmpw; Spell tmps;
#define END_GAME return 0;}
#define CREATE ;
#define DUEL ; Game::duel();


// WIZARDS

#define WIZARD tmpw = Wizard
#define WIZARDS Wizard {}

#define NAME .name = (false)?""
#define HOUSE .house = (false)?""
#define HP .hp = (false)?0

// SPELLS

#define SPELL tmps = Spell
#define SPELLS Spell {}
#define ACTION .action = (false)?[](Wizard *attacker, Wizard *defender, Spell *source){}
#define START [](Wizard *attacker, Wizard *defender, Spell *source) {\
    int round_offset = 0; Action dummy;
#define END ; }
#define O Wand()
#define _ Wand()

#define ATTACKER attacker=
#define DEFENDER defender=

#define DAMAGE ; dummy = Action(1, attacker, source) = *
#define HEAL ; dummy = Action(2, attacker, source) = *
#define EQUIP ; dummy = Action(3, attacker, source) = *

#define GET_HP(wizard) (*wizard 0)->hp
#define GET_HOUSE(wizard) (*wizard 0)->house
#define GET_NAME(wizard) (*wizard 0)->name
#define HAS_WAND(wizard) (*wizard 0)->wand

#define AND Game::and_f
#define OR Game::or_f
#define NOT Game::not_f

#define IF ;flag=0; if (
#define ELSE_IF ;}; else if (
#define ELSE ;}; else {
#define DO ) Game::addActionBlock(attacker, defender, source, round_offset) = [](Wizard *attacker, Wizard *defender, Spell *source) { \
    int round_offset = 0; Action dummy;

// FOR 2 ROUNDS DO
// for (round offset=0; round_offset< 2 ; round_offset++)
// after 2 rounds do
// for (round_offset=0; round_offset+= 2 ; round_offset++)
// for (round_offset=0;  if(1) round_offset+= 2 //; round_offset++)
#define FOR ; for (round_offset=0; round_offset<
#define ROUNDS ; round_offset++
#define AFTER ;if (round_offset=
// define AFTER ;while(round_offset< 5 ; round_offset++) DO...
// if ( true || round_offset=X   ;round_offset++   ) Game::addActionBlock
//        AFTER     | X  |         ROUNDS          DO
#define SHOW ;cout<<


// SPELL LEARNING

#define MR ;Wizard::getWizard(
#define MRS ;Wizard::getWizard(
#define LEARN )
#define SPELL_NAME(X) #X" "