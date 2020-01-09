//
// Created by manos on 12/24/19.
//
#pragma once

#include "classes/debug.h"
#include "classes/Wizard.h"
#include "classes/Spell.h"
#include "classes/Game.h"
#include <iostream>

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
#define START [](Wizard& attacker, Wizard& defender) {
#define END ;}
//#define ---α true
#define _ false

// #define OP (
// #define CP )

#define MACRO_REDUCE_HP(x, wizard) x + wizard
#define MACRO_DAMAGE(x) MACRO_REDUCE_HP(x,
#define MACRO_ATTACKER(wizard) wizard)

#define WATTACKER attacker
#define WDEFENDER defender

#define ATTACKER WATTACKER)
#define DEFENDER WDEFENDER)

#define DAMAGE ;REDUCE_HP(
#define REDUCE_HP(wizard) wizard -

#define HEAL ;INCREASE_HP(
#define INCREASE_HP(wizard) wizard +
 
#define EQUIP ;

#define GET_HP(wizard) ;Game::get_hp(wizard
#define GET_HOUSE(wizard) ;Game::get_house(wizard
#define GET_NAME(wizard) ;Game::get_name(wizard
#define HAS_WAND(wizard) ;Game::has_wand(wizard

#define AND Game::and_f
#define OR Game::or_f
#define NOT Game::not_f

#define IF ;if (
#define ELSE_IF ;} else if (
#define ELSE ;} else {
#define DO ) {

#define FOR for (int i=0; i<
#define ROUNDS ; i++

#define SHOW cout<<


// SPELL LEARNING

#define MR ;SPELL_VECTOR Wizard::getWizard(
#define MRS ;Wizard::getWizard(
#define LEARN )
#define SPELL_NAME(X) #X" "