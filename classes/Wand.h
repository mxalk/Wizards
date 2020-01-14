//
// Created by manos on 1/14/20.
//
#pragma once
#include <string>
#include <iostream>

using namespace std;

class Wand {
public:
    bool wand;
    Wand():wand(false){
    };
    Wand operator--() {
        return *this;
    }
    Wand operator-() {
        this->wand = !this->wand;
        return *this;
    }
};

