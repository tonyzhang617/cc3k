cmake_minimum_required(VERSION 3.8)
project(cc3k_clion)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        item.cc
        item.h
        subject.cc
        subject.h
        character.cc
        character.h
        NPCs/dragon.cc
        NPCs/dragon.h
        PCs/drow.cc
        PCs/drow.h
        NPCs/dwarf.cc
        NPCs/dwarf.h
        NPCs/elf.cc
        NPCs/elf.h
        NPCs/enemy_character.cc
        NPCs/enemy_character.h
        enum.h
        PCs/goblin.cc
        PCs/goblin.h
        grid.cc
        grid.h
        NPCs/halfling.cc
        NPCs/halfling.h
        NPCs/human.cc
        NPCs/human.h
        main.cc
        Makefile
        NPCs/merchant.cc
        NPCs/merchant.h
        NPCs/orcs.cc
        NPCs/orcs.h
        PCs/player_character.cc
        PCs/player_character.h
        PCs/shade.cc
        PCs/shade.h
        PCs/troll.cc
        PCs/troll.h
        PCs/vampire.cc
        PCs/vampire.h enum.cc observer.cc)

add_executable(cc3k_clion ${SOURCE_FILES})