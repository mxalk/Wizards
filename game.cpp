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
        NAME: "spell1",
        ACTION: START
//                DAMAGE ATTACKER 25
//                HEAL DEFENDER 20
//                EQUIP DEFENDER _
//                EQUIP ATTACKER ---α
                IF GET_HP(DEFENDER) <= 20 DO
//                    DAMAGE DEFENDER 10
                ELSE_IF GET_HP(DEFENDER) <= 50 DO
//                    DAMAGE DEFENDER 20
                ELSE
//                    DAMAGE DEFENDER 30
                END
        END
    }
            CREATE SPELLS [
                SPELL {
                    NAME: "spell2",
                    ACTION: START
                    END
                },
                SPELL {
                NAME: "spell3",
                    ACTION: START
                    END
                }
    ]
    ;
//
//DUEL

END_GAME