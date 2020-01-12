//
// Created by antap on 1/9/2020.
//

#include "Round.h"

using namespace std;

Round::Round() : general(1), player1(1), player2(1) {}

void Round::print_round() {
    TILDES;
    cout << "Round " << this->general << endl;
    TILDES;
}




