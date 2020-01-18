cmake_minimum_required(VERSION 3.15)
project(Wizards)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(classes)

add_executable(Wizards
        Hogwarts.h
        game_translate.cpp
        classes/Wizard.cpp
        classes/Wizard.h
        classes/Spell.cpp
        classes/Spell.h
        classes/Game.h
        classes/Action.h
        classes/global.h
        classes/Action_Block.h)
