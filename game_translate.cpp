//
// Created by manos on 12/24/19.
//
#include "Hogwards.h"

#include <vector>
#include <string>
#include <stack>

using namespace std;

void test() {
    Wizard tmpw;
    Spell tmps

    ; tmpw = Wizard {
            .name = (false)?"": "Harry Potter",
            .house = (false)?"": "Gryffindor",
            .hp = (false)?0: 120
    }

    ; Wizard {} [
            tmpw = Wizard {
                NAME: "HermioneGranger",
                HOUSE: "Gryffindor",
                HP: 120
            },
            tmpw = Wizard {
                  NAME: "LunaLovegood",
                  HOUSE: "Ravenclaw",
                  HP: 85
            }
    ]

    ; tmps = Spell {
            .name = (false)?"": "spell1",
                .action = (false)?[](Wizard& attacker, Wizard& defender) {}:
                        [](Wizard& attacker, Wizard& defender) -> void {
                stack <int> depth;
                depth.push(0);\
                int round_offset = 0;
//               ; Action_Damage action; action.setAttacker(attacker); action.setDefender(attacker) 25
//                ;DAMAGE defender 20
//                ;EQUIP defender _
//                ;EQUIP attacker ---α
                ; depth.push(round_offset); if ( defender.hp <= 20 ) Game::getRound(round_offset) = [](Wizard& attacker, Wizard& defender) {
//                            DAMAGE DEFENDER 10
                            attacker.damage(defender, 10);
                ;}; else if ( defender.hp <= 50 ) Game::getRound(round_offset) = [](Wizard& attacker, Wizard& defender) {
//                            DAMAGE DEFENDER 20
                                attacker.damage(defender, 20);
                ;}; else Game::getRound(round_offset) = [](Wizard& attacker, Wizard& defender) {
//                            DAMAGE DEFENDER 30
                                attacker.damage(defender, 30);
                ;}; round_offset = depth.top(); depth.pop();
                ; depth.push(round_offset); for (round_offset=0; round_offset<5; round_offset++) Game::getRound(round_offset) = [](Wizard& attacker, Wizard& defender) {
//                            DAMAGE DEFENDER 30
                                attacker.damage(defender, 30);
                ;}; round_offset = depth.top(); depth.pop();
            ;}
    }
    ;tmps = Spell {
            .name = (false)?"": "spell2",
            .action = (false)?[](Wizard& attacker, Wizard& defender) {}:
                      [](Wizard& attacker, Wizard& defender) -> void {
                              SHOW "LALALAL"
                      ;}
    }

//     ;Wizard::getWizard("HermioneGranger") [
//        spells_learn.push_back(Spell::getSpell("spell1"));
//        spells_learn.push_back(Spell::getSpell("spell2"));
//    ]
//    ; Wizard::getWizard("HermioneGranger") [
//        Spell::getSpell("spell1") +
//        Spell::getSpell("spell2") +
//    ]
    ; Wizard::getWizard("HermioneGranger") [
        "spell1" " " "spell2" " "
    ]
//DUEL
;
}