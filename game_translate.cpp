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
    ;
//CREATE WIZARD {
//    NAME: "Darko Malfoy",
//    HOUSE: "Slythernet",
//    HP: 100
//}
//
//CREATE SPELL {
//    NAME: "spell_name",
//    ACTION: START
//            END
//}
//
//DUEL

}