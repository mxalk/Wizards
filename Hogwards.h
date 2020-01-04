//
// Created by manos on 12/24/19.
//
#pragma once

#include "classes/Wizard.h"
//#include "classes/Characteristic.h"

//#include <vector>
//#include <string>

#define BEGIN_GAME int main() { vector<Wizard *> wizards;
#define END_GAME return 0;}
#define DUEL duel();

#define CREATE ;

#define WIZARD Wizard *tmp = new Wizard; wizards.push_back(tmp); *tmp = Wizard
#define WIZARDS Wizard

#define NAME .name = (false)?""
#define HOUSE .house = (false)?""
#define HP .hp = (false)?0

using namespace std;

//Wizard Wizard :: operator=(initializer_list<Characteristic>) {
//                // body of the function.
//}


void duel() {

}