//
// Created by manos on 1/6/20.
//
#pragma once

#include "classes/Wizard.h"
#include "classes/Spell.h"
#include "global.h"
#include "Action_Block.h"
#include "Action.h"
#include <list>
#include <string>
#include <cstdarg>
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

class Wizard;
class Spell;
class Game {
public:
    inline static vector<Action_Block *> actions;
    inline static list<Wizard *> turns;
    inline static int players;
    inline static Wizard **wizards;

    static Action_Block &addActionBlock(Wizard *attacker, Wizard *defender, Spell *source, int rounds_total) {
        auto *ab = new Action_Block(attacker, defender, source, rounds_total);
        actions.push_back(ab);
        return *ab;
    }

    static void cast(Wizard *attacker, Wizard *defender, Spell *source) {
        cout << "Player " << attacker->player_number << " (" << attacker->name << ") casts "
             << source->name << " targeting ";
        if(attacker!=defender) {
            cout << "Player " << defender->player_number << " (" << defender->name << ")" << endl;
        } else cout << "self" << endl;
        Action_Block ab(attacker, defender, source, 0);
        ab = source->action;
        ab.play();
    }

    static void play(Wizard *player, bool spellcasting_phase) {
        Action_Block *block;
        bool replay;
        do {
            replay = false;
//            cout << "--------------------------------SIZE: " << actions.size() << endl;
            for (auto it = actions.begin(); it != actions.end();) {
                block = *it;
//                cout << "--------------------------------BLOCK MIGHT BE EXECUTED " << player << " rounds:" << block->rounds_remaining << " defender:" << block->defender << " attacker:" << block->attacker << endl;
                if (block->rounds_remaining > 0 || (/*!spellcasting_phase && block->defender != player) || (spellcasting_phase && */block->defender != player && block->attacker != player)) {
                    it++;
                    continue;
                }
//                cout << "--------------------------------BLOCK IS BEING EXECUTED" << endl;
                block->play();
                actions.erase(it);
                free(block);
                replay = true;
            }
        } while (replay);
    }

    template <typename Arg>
    static bool and_func(Arg arg1, Arg arg2) {return arg1 && arg2;}

    template <typename Firsts, typename... The>
    static bool and_func(Firsts arg1, Firsts arg2, The... rest) {
            bool tmp = arg1 && arg2;
            and_func(arg1,arg2);
            return and_func(tmp, rest...);
    }

    template <typename Arg>
    static bool or_func(Arg arg1, Arg arg2) {return arg1 || arg2;}

    template <typename Firsts, typename... The>
    static bool or_func(Firsts arg1, Firsts arg2, The... rest) {
            bool tmp = arg1 || arg2;
            or_func(arg1,arg2);
            return or_func(tmp, rest...);
    }

    static bool not_f(bool arg) { return !arg; };

    static void printall() {
        Wizard::print_wizards();
        Spell::print_spells();
    };

    static int choose_players(const string& input) {
        try {
            int i = stoi(input);
            if (i < 2) return 0;
            return i;
        } catch (exception const &e) {}
        return 0;
    }
    static Wizard *choose_wizard(const string& input, int player_number) {
        for (const Wizard &w:Wizard::all_wizards) if (w.name == input) return w.choose(player_number);
        Wizard *w;
        try {
            int i = stoi(input);
            w = &Wizard::all_wizards.at(i-1);
            if (w->spells.empty()) {
                cout << "Can't select " << w->name << " because the wizard knows no spells!" << endl;
                return nullptr;
            }
            return w->choose(player_number);
        } catch (exception const &e) {}
        return nullptr;
    }

    static int alive_players_remaining() {
        int alive_players = 0;
        for (int i=0; i<players; i++) if (wizards[i]->hp > 0) alive_players++;
        return alive_players;
    }

    static bool more_game() {
        int alive_players = alive_players_remaining();
        switch(alive_players) {
            case 0:
                cout << "DRAW! All wizards have been eliminated";
                break;
            case 1:
                for (int i=0; i<players; i++) if (wizards[i]->hp > 0) {
                    cout << "Player " << i+1 << " (" << wizards[i]->name << ") VICTORIOUS!" << endl;
                    break;
                }
                break;
            default:
                return true;
        }
        exit(0);
    }

    static void reset_turns() {
        for (int i = 0; i<players; i++) turns.push_back(wizards[i]);
    }

    static Spell *choose_spell(Wizard *player) {
        Spell *s;
        string input;
        do {
            player->print_spells_choose();
            getline (cin, input);
            if (input == "exit") exit(-1);
            s = player->getSpell(input);
            if (!s) {
                try {
                    int i = stoi(input);
                    s = player->getSpell(i-1);
                } catch (exception const &e) {
                    cout << endl << R"(!INVALID CHOICE!!)" << endl;
                }
            }
        } while (!s);
        cout << "Player "<< player->player_number << " selected Spell: " << s->name <<endl;
        cout << endl;
        return s;
    }

    static void print_targets() {
        Wizard *w;
        for (int i = 0; i<players; i++) {
            w = wizards[i];
            cout << i+1 << ".) (" << w-> name << ") Player " << w->player_number << endl;
        }
    }

    static Wizard *choose_target(int player_number) {
        if (Game::players == 2) {
            for (int i = 0; i<players; i++) if (wizards[i]->player_number != player_number) return wizards[i];
        }
        Wizard *w;
        string input;
        int i;
        bool invalid;
        do {
            cout << "Player "<< player_number << " selects target:" << endl
                 << "--------------------------" << endl;
            Game::print_targets();
            cout << "--------------------------" << endl;
            cout << "Choose [1-" << players << " // Name]:";
            getline (cin, input);
            if (input == "exit") exit(-1);
            invalid = false;
            try {
                i = stoi(input);
                if (i < 1 || i > players) invalid = true;
            } catch (exception const &e) {
                invalid = true;
            }
            if (invalid) cout << endl << R"(!INVALID CHOICE!!)" << endl;
        } while (invalid);
        return wizards[i-1];
    }

//    #define WIZARD_WIDTH 24
//    #define HP_WIDTH 20
//    void print_wizards() {
//        int i;
//        Wizard *w;
//        for (i=0; i<players; i++) {
//            w = wizards[i];
//            cout
//        }
//        string tmp = "";
//        for (int i=0; i<HP_WIDTH*this->hp/this->max_hp; i++) tmp += '#';
//        for (int i=0; i<HP_WIDTH-HP_WIDTH*this->hp/this->max_hp; i++) tmp += ' ';
//        cout <<        "***************************" << endl
//             << "Player: " << this->player_number << endl
//             << "Name: " << this->name << endl
//             << "[ " << tmp << " ]" << endl;
//        cout << "Hp: " << this->hp << "/" << this->max_hp << endl;
//        if (this->wand) cout << "-----@";
//        else            cout << "-----X";
//        cout << endl << "***************************" << endl;
//    }

    static void duel() {
        int p, wizards_size_choose = Wizard::all_wizards.size(), tmp;
        bool invalid_choice;
        string input;
        Wizard *player, *target;
        Spell *s;

        cout << "----------------------------------- HARRY POTTER THE GAME -----------------------------------" << endl << endl;

        do {
            cout << "Enter # of Players[2+]:" << endl;
            getline (cin, input);
            if (input == "exit") exit(-1);
            players = Game::choose_players(input);
            if (!players) cout << endl << R"(!INVALID CHOICE!!)" << endl;
        } while (!players);

        wizards = new Wizard*[players];

        for (tmp = 0; tmp<players; tmp++) {
            do {
                cout << "Player "<< tmp+1 << " selects wizard:" << endl
                     << "--------------------------" << endl;
                Wizard::print_wizards();
                cout << "--------------------------" << endl;
                cout << "Choose [1-" << wizards_size_choose << " // Name]:";
                getline (cin, input);
                if (input == "exit") exit(-1);
                wizards[tmp] = Game::choose_wizard(input, tmp+1);
                if (!wizards[tmp]) cout << endl << R"(!INVALID CHOICE!!)" << endl;
            } while (!wizards[tmp]);
            cout << "Player "<< tmp+1 << " selected wizard: " << wizards[tmp]->name <<endl;
            cout << endl;
        }

        game_round = 0;
        while (more_game()) {
            game_round++;
            PRINT_ROUND(game_round);
            reset_turns();
            while (!turns.empty()) {
                player = turns.front();
                turns.pop_front();
                player->ravenclaw_heal();
                for (auto & action : actions) if (action->attacker == player) action->rounds_remaining--;
                Game::play(player, false);
                for (int i = 0; i<players; i++) {wizards[i]->print_status(); cout<<endl;}
                if (player->hp == 0) continue;
                if (!player->wand) {
                    cout << "Player " << player->player_number << " has no wand!" << endl;
                    continue;
                }
                s = choose_spell(player);
                target = choose_target(player->player_number);
                Game::cast(player, target, s);;
                Game::play(player, true);
            }
        }
    }
};
