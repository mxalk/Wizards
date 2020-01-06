//
// Created by manos on 12/24/19.
//
#include "Hogwards.h"

#include <vector>
#include <string>

using namespace std;

void test() {
    Wizard tmp;

    ; tmp = Wizard {
            .name = (false)?"": "Harry Pointer",
            .house = (false)?"": "GryffinTOR",
            .hp = (false)?0: 120
    }

    ; WIZARDS [
            Wizard {
                    .name = (false)?"": "Harry Pointer",
                    .house = (false)?"": "GryffinTOR",
                    .hp = (false)?0: 120
            },
            tmp = Wizard {
                NAME: "HermioneGranger",
                HOUSE: "Gryffindor",
                HP: 120
            },
            tmp = Wizard {
                  NAME: "LunaLovegood",
                  HOUSE: "Ravenclaw",
                  HP: 85
            }
    ]

    ; tmps = Spell {
            .name = (false)?"": "test",
            .action = (false)?[](Wizard& attacker, Wizard& defender){}:
                    [](Wizard& attacker, Wizard& defender) {
                ; attacker 25
                ; defender 20
                ; defender _
                ; attacker ---α
                ;Game::get_hp(defender)
            ;}
    }
//DUEL

}