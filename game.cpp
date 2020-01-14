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
                 IF GET_HP(DEFENDER) <= 20 DO
                        SHOW "DAMAGING " << 10 << endl;
 //                    DAMAGE DEFENDER 10
                    attacker->damage(defender, 10);
                 ELSE_IF GET_HP(DEFENDER) <= 50 DO
                        SHOW "DAMAGING " << 20 << endl;
 //                    DAMAGE DEFENDER 20
                    attacker->damage(defender, 20);
                 ELSE
                        SHOW "DAMAGING " << 30 << endl;
 //                    DAMAGE DEFENDER 30
                    attacker->damage(defender, 30);
//                     SHOW "LALALLA1"
                 END
//                 SHOW "AFTER START" << endl;
//                AFTER 1 ROUNDS DO
//                    SHOW "AFTER 1" << endl;
//                    attacker->damage(defender, 20);
//                END
//            SHOW "AFTER END" << endl;

                 FOR 5 ROUNDS DO
                    SHOW "NESTED" << endl;
                     IF GET_HP(ATTACKER) > 20 DO
                         SHOW "NESTED IF" << endl;
                     END
                     ;attacker->damage(defender, 20);
                     attacker->heal(attacker, 20);
                 END
                // AFTER 2 ROUNDS DO
                //     attacker->damage(defender, 25);
                // END
        END
    }
    CREATE SPELLS [
            SPELL {
                    NAME: "spell2",
                    ACTION: START
                SHOW "LALALLA2\n"
                    END
            },
            SPELL {
                    NAME: "spell3",
                    ACTION: START
                        SHOW "LALALLA3\n"
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




