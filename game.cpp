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
//    MRS "HermioneGranger" LEARN [
//            SPELL_NAME(spell1)
//            SPELL_NAME(spell2)
//    ]
//
//DUEL
Game::printall();
END_GAME

/*
#define DASHES std::cout<<"------------------"<<endl
#define TILDES std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl
#define HASHES std::cout<<"##################"<<endl

void duel() {

        std::string str1;
        std::string str2;

        cout << "-------------------------HARRY POTTER THE GAME------------------------" << endl << endl;
        cout << "Player1 select wizard:" << endl;
        DASHES;
        Wizard::print_wizards_names();
        DASHES;
        getline (std::cin, str1);

        cout << "Player2 select wizard:" << endl;
        DASHES;
        Wizard::print_wizards_names();
        DASHES;
        getline (std::cin, str2);

        Wizard w1 = Wizard::getWizard(str1);
        
        if (str1.compare(str2) != 0) { 
                Wizard w2 = Wizard::getWizard(str2);
        } else {
                // copy constructor
        } 

        while ( game::get_hp(w1) > 0 && game::get_hp(w2) > 0) {
                print_round(  );
                
                // if(player1.wand) {
                //      Spell sp1
                //      string s1
                //      spell_select(player1)
                //      players_status()
                // } else print_no_wand_msg
                
                // if(player2.wand) {
                //      Spell sp2
                //      string s2     
                //      spell_select(player2)
                //      players_status()
                // } else print_no_wand_msg

                // round++ 
        }

} 

void print_round(int round) {
        TILDES;
        cout << "Round " << round << endl;
        TILDES;
}

/////////////////////
spell_select () {
        cout << name_1 << ...... ;
        DASHES;
        print_w1_spell_list()         
        DASHES;
        getline (std::cin, s1);
        sp1 = Wizard::getSpell(s1);  
}

*/