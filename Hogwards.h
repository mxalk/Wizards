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
#define ATTACKER attacker
#define DEFENDER defender
#define DAMAGE ;
#define HEAL ;
#define EQUIP ;

#define GET_HP ;Game::get_hp
#define GET_HOUSE ;Game::get_house
#define GET_NAME ;Game::get_name
#define HAS_WAND ;Game::has_wand

#define AND Game::and_f
#define OR Game::or_f
#define NOT Game::not_f

#define IF if (
#define ELSE_IF else if (
#define ELSE else {
#define DO ) {

#define FOR for (int i=0; i<
#define ROUNDS ; i++

#define SHOW cout<<