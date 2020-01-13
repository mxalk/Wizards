//
// Created by manos on 12/24/19.
//
#include "Hogwards.h"

BEGIN_GAME

    CREATE WIZARD{
            NAME : "Harry Potter",
            HOUSE : "Gryffindor",
            HP : 120
    }

    CREATE WIZARDS[
        WIZARD{
                NAME : "Hermione Granger",
                HOUSE : "Gryffindor",
                HP : 120
        },
        WIZARD{
                NAME : "Luna Lovegood",
                HOUSE : "Ravenclaw",
                HP : 85
        }
    ]

    CREATE WIZARD {
        NAME: "Draco Malfoy",
        HOUSE: "Slytherin",
        HP: 100
    }
    CREATE SPELL {
        NAME: "spell1",
        ACTION: START
//               DAMAGE ATTACKER 25
//                HEAL DEFENDER 20
//                EQUIP DEFENDER _
//                EQUIP ATTACKER ---α
//                 IF GET_HP(DEFENDER) <= 20 DO
// //                    DAMAGE DEFENDER 10
//                 ELSE_IF GET_HP(DEFENDER) <= 50 DO
// //                    DAMAGE DEFENDER 20
//                 ELSE
// //                    DAMAGE DEFENDER 30
//                     SHOW "LALALLA1"
//                 END

                // FOR 5 ROUNDS DO
                //     IF GET_HP(ATTACKER) > 20 DO
                //         SHOW round_offset
                //     END
                // END
                // AFTER 2 ROUNDS DO
                //     attacker->damage(defender, 25);
                // END
        END
    }
    CREATE SPELLS [
            SPELL {
                    NAME: "spell2",
                    ACTION: START
                SHOW "LALALLA2"
                    END
            },
            SPELL {
                    NAME: "spell3",
                    ACTION: START
                        SHOW "LALALLA3"
                    END
            }
    ]
    MRS "Harry Potter" LEARN [
        SPELL_NAME(spell1)
        SPELL_NAME(spell3)
    ]
    
    MRS "Hermione Granger" LEARN [
        SPELL_NAME(spell1)
        SPELL_NAME(spell2)
    ]
    MRS "Luna Lovegood" LEARN [
        SPELL_NAME(spell3)
    ]

DUEL
END_GAME




