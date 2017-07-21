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
        gold/dragon_hoard.cc
        gold/dragon_hoard.h
        gold/gold.cc
        gold/gold.h
        gold/merchant_hoard.cc
        gold/merchant_hoard.h
        gold/normal_hoard.cc
        gold/normal_hoard.h
        gold/normal_hoardl.h
        gold/small_hoard.cc
        gold/small_hoard.h
        potion/boost_attack.cc
        potion/boost_attack.h
        potion/boost_defense.cc
        potion/boost_defense.h
        potion/poison_health.cc
        potion/poison_health.h
        potion/potion.cc
        potion/potion.h
        potion/restore_health.cc
        potion/restore_health.h
        potion/wound_attack.cc
        potion/wound_attack.h
        potion/wound_defense.cc
        potion/wound_defense.h
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
        PCs/vampire.h enum.cc observer.cc factory/factory.cc factory/factory.h factory/pc_factory.cc factory/pc_factory.h factory/enemy_factory.cc factory/enemy_factory.h factory/stair_factory.cc factory/stair_factory.h factory/potion_factory.cc factory/potion_factory.h)

add_executable(cc3k_clion ${SOURCE_FILES})