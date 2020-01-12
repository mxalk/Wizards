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
//                    DAMAGE DEFENDER 10
                ELSE_IF GET_HP(DEFENDER) <= 50 DO
//                    DAMAGE DEFENDER 20
                ELSE
//                    DAMAGE DEFENDER 30
                SHOW "LALALLA1"
                END
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
     MRS "HermioneGranger" LEARN [
             SPELL_NAME(spell1)
             SPELL_NAME(spell2)
         ]
//DUEL
;
Game::printall();
Spell::all_spells.at(1).action(Wizard::all_wizards.at(0), Wizard::all_wizards.at(1));
END_GAME

/*
void duel() {

        std::string str1;
        std::string str2;

        cout << "-------------------------HARRY POTTER THE GAME------------------------" << endl << endl;
        cout << "Player1 select wizard:" << endl
             << "------------------" << endl;
        Wizard::print_wizards_names();
        cout << "------------------" << endl;
        getline (std::cin, str1);

        cout << "Player2 select wizard:" << endl
             << "------------------" << endl;
        Wizard::print_wizards_names();
        cout << "------------------" << endl;
        getline (std::cin, str2);

        Wizard w1 = Wizard::getWizard(str1);
        
        if (str1.compare(str2) != 0) { 
                Wizard w2 = Wizard::getWizard(str2);
        } else {
                // need a copy of wizard 1
        } 

        Round round;
        while ( w1.getHp() > 0 && w2.getHp() > 0) {
                round.print_round();

                if (w1.hasWand()) {
                        Spell sp1;      string s1;
                        w1.spell_select(1);
                        getline (std::cin, s1);
                        //sp1 = Wizard::getSpell(s1);   implement getSpell
                        w1.print_status();
                        w2.print_status();
                } else {
                        w1.print_wizard_name();
                        cout << "(Player1) has no wand equipped, can't cast spell." << endl;
                }

                if(w2.hasWand()) {
                        Spell sp2;      string s2;
                        w2.spell_select(2);
                        getline (std::cin, s2);
                        //sp2 = Wizard::getSpell(s2);
                        w1.print_status();
                        w2.print_status();
                } else {
                        w2.print_wizard_name();
                        cout << "(Player2) has no wand equipped, can't cast spell." << endl;
                }

                // round++ na kano overload to increment
        }

} 

*/