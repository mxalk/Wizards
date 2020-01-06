//
// Created by manos on 12/24/19.
//
#include "Hogwards.h"

BEGIN_GAME

    CREATE WIZARD{
            NAME : "Harry Pointer",
            HOUSE : "GryffinTOR",
            HP : 120
    }
    CREATE WIZARDS[
        WIZARD{
                NAME : "HermioneGranger",
                HOUSE : "Gryffindor",
                HP : 120
        },
        WIZARD{
                NAME : "LunaLovegood",
                HOUSE : "Ravenclaw",
                HP : 85
        }
    ]

    CREATE WIZARD {
        NAME: "Darko Malfoy",
        HOUSE: "Slythernet",
        HP: 100
    }

    CREATE SPELL {
        NAME: "spell_name",
        ACTION: START
                END
    }
            CREATE SPELLS [
                SPELL {
                    NAME: "spell_name",
                    ACTION: START
                    END
                },
                SPELL {
                NAME: "spell_name",
                    ACTION: START
                    END
                }
    ]
    ;
//
//DUEL

END_GAME