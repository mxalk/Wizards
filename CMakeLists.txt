cmake_minimum_required(VERSION 3.15)
project(Wizards)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(classes)

add_executable(Wizards
        game.cpp
        game_translate.cpp
        Hogwards.h
        classes/Wizard.cpp
        classes/Wizard.h
        classes/Spell.cpp
        classes/Spell.h
        classes/Game.h
        classes/Action.h
        classes/Action_Damage.h
        classes/global.h
        classes/global.cpp
        classes/Action_Block.h)
