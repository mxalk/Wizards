//
// Created by manos on 1/10/20.
//
#pragma once

class Action {
public:
    int action{};
    Wizard *attacker;
    Spell *source{};

    Action() = default;
    Action(int action, Wizard *attacker, Spell *source):action(action), attacker(attacker), source(source) {}

    Action &operator=(Wizard *defender) {
        int actual;
        switch (this->action) {
            case 1:
                actual = this->attacker->damage(defender, defender->action_amount);
                cout << actual << " damage inflicted to ";
                Action::prints(attacker, defender);
                cout << source->name << endl;
                break;
            case 2:
                actual = this->attacker->heal(defender, defender->action_amount);
                cout << actual << " health restored to ";
                Action::prints(attacker, defender);
                cout << source->name << endl;
                break;
            case 3:
                cout << "WAND TO EQUIP IS " << defender->wand_to_have << endl;
                this->attacker->equip(defender, defender->wand_to_have);
                cout << "Player " << defender->player_number << " (" << defender->name << ")'s wand is now ";
                if (defender->wand_to_have) {
                    cout << "equipped";
                } else cout << "not equipped";
                cout << endl;
                break;
            default:
                throw exception();
        }
        return *this;
    }

    static void prints(Wizard *attacker, Wizard *defender) {
        if (attacker != defender) {
            cout << "Player " << defender->player_number << " (" << defender->name << ") by "
                    << "Player " << attacker->player_number << " (" << attacker->name << ")'s ";
        } else cout << "self by ";
    }
};
