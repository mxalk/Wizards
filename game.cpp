//
// Created by manos on 12/24/19.
//
#include "Hogwards.h"

#include <vector>
#include <string>

using namespace std;

BEGIN_GAME

CREATE WIZARD{
            NAME : "Harry Pointer",
            HOUSE : "GryffinTOR",
            HP : 120
    }
    (initializer_list<Wizard>(), nullptr, 0)CREATE WIZARDS[
        WIZARD{
                NAME : "HermioneGranger",
                HOUSE : "Gryffindor",
                HP : 120
        }
    (initializer_list<Wizard>(), nullptr, 0),
        WIZARD{
                NAME : "LunaLovegood",
                HOUSE : "Ravenclaw",
                HP : 85
        }
    (initializer_list<Wizard>(), nullptr, 0)
    ]
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

END_GAME