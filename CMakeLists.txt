cmake_minimum_required(VERSION 3.15)
project(Wizards)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Wizards
        game.cpp
        game_translate.cpp
        Hogwards.h
        classes/Wizard.cpp
        classes/Wizard.h classes/debug.h classes/Spell.cpp classes/Spell.h classes/Game.cpp classes/Game.h)
