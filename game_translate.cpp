//
// Created by manos on 12/24/19.
//
#include "Hogwards.h"

#include <vector>
#include <string>

using namespace std;

void test() {
    Wizard tmpw;
    Spell tmps

    ; tmpw = Wizard {
            .name = (false)?"": "Harry Pointer",
            .house = (false)?"": "GryffinTOR",
            .hp = (false)?0: 120
    }

    ; Wizard {} [
            tmpw = Wizard {
                    .name = (false)?"": "Harry Pointer",
                    .house = (false)?"": "GryffinTOR",
                    .hp = (false)?0: 120
            },
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
               ; attacker.hp += 25
//                ;DAMAGE defender 20
//                ;EQUIP defender _
//                ;EQUIP attacker ---α
                ; if ( Game::get_hp(defender) <= 20 ) {
//                            DAMAGE DEFENDER 10
                ; } else if ( Game::get_hp(defender) <= 50 ) {
//                            DAMAGE DEFENDER 20
                ; } else {
//                            DAMAGE DEFENDER 30
                ; }
            ;}
    }
    ;tmps = Spell {
            .name = (false)?"": "spell2",
            .action = (false)?[](Wizard& attacker, Wizard& defender) {}:
                      [](Wizard& attacker, Wizard& defender) -> void {
                              SHOW "LALALAL"
                      ;}
    }

//     ;Wizard::getWizard("HermioneGranger") = [
//        SPELL_NAME(spell1)
//        SPELL_NAME(spell2)
//    ]
//DUEL
;
}