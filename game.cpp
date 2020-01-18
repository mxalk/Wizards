//
// Created by manos on 12/24/19.
//
#include "Hogwarts.h"

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
        NAME: "BOOM",
        ACTION: START
//               DAMAGE ATTACKER 25
//                HEAL DEFENDER 20
//                EQUIP DEFENDER _
//                EQUIP ATTACKER ---α
                 IF GET_HP(DEFENDER) <= 20 DO
                     DAMAGE DEFENDER 10
                 ELSE_IF GET_HP(DEFENDER) <= 50 DO
                     DAMAGE DEFENDER 20
                 ELSE
                     DAMAGE DEFENDER 30
                 END
//                 SHOW "AFTER START" << endl;
//                AFTER 1 ROUNDS DO
//                    SHOW "AFTER 1" << endl;
//                    attacker->damage(defender, 20);
//                END
//            SHOW "AFTER END" << endl;

//                 FOR 5 ROUNDS DO
//                    SHOW "NESTED" << endl;
//                     IF GET_HP(ATTACKER) > 20 DO
//                         SHOW "NESTED IF" << endl;
//                     END
////                     ;attacker->damage(defender, 20);
////                     attacker->heal(attacker, 20);
//                 END
                // AFTER 2 ROUNDS DO
                //     attacker->damage(defender, 25);
                // END
        END
    }
    CREATE SPELLS [
            SPELL {
                    NAME: "DAMAGE",
                    ACTION: START
                        DAMAGE DEFENDER 30
                    END
            },
            SPELL {
                    NAME: "HEAL",
                    ACTION: START
                        HEAL ATTACKER 30
                    END
            },
            SPELL {
                    NAME: "DOT",
                    ACTION: START
                            FOR 5 ROUNDS DO
                                    DAMAGE DEFENDER 10
                            END
                    END
            },
            SPELL {
                    NAME: "HOT",
                    ACTION: START
                            FOR 5 ROUNDS DO
                                    HEAL ATTACKER 10
                            END
                    END
            },
            SPELL {
                    NAME: "UNEQUIP",
                    ACTION: START
                            DAMAGE DEFENDER 5
                            EQUIP DEFENDER _
                            AFTER 1 ROUNDS DO
                                    SHOW "AFTER 1" << endl;
                                    EQUIP DEFENDER ---O
                            END
                    END
            },
            SPELL {
                    NAME: "AFTER_TEST",
                    ACTION: START
                            AFTER 1 ROUNDS DO
                                    SHOW "AFTER 1" << endl;
                            END
                    END
            }
    ]
    MRS "Harry Potter" LEARN [
            SPELL_NAME(DAMAGE)
            SPELL_NAME(HEAL)
            SPELL_NAME(DOT)
            SPELL_NAME(HOT)
            SPELL_NAME(UNEQUIP)
            SPELL_NAME(AFTER_TEST)
    ]
    MRS "Hermione Granger" LEARN [
            SPELL_NAME(DAMAGE)
            SPELL_NAME(HEAL)
            SPELL_NAME(DOT)
            SPELL_NAME(HOT)
            SPELL_NAME(UNEQUIP)
    ]
    MRS "Luna Lovegood" LEARN [
            SPELL_NAME(DAMAGE)
            SPELL_NAME(HEAL)
            SPELL_NAME(DOT)
            SPELL_NAME(HOT)
            SPELL_NAME(UNEQUIP)
    ]
    MRS "Draco Malfoy" LEARN [
            SPELL_NAME(DAMAGE)
            SPELL_NAME(HEAL)
            SPELL_NAME(DOT)
            SPELL_NAME(HOT)
            SPELL_NAME(UNEQUIP)
    ]

DUEL
END_GAME




