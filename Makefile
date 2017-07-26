CXX = g++
CXXFLAGS = -std=c++14 -Wall -Werror -MMD
EXEC = cc3k
MAIN_OBJ = main.o grid.o enum.o character.o item.o observer.o subject.o
FACTORY_OBJ = factory/enemy_factory.o factory/factory.o factory/gold_factory.o factory/pc_factory.o factory/potion_factory.o factory/stair_factory.o
GOLD_OBJ = gold/dragon_hoard.o gold/gold.o gold/merchant_hoard.o gold/normal_hoard.o gold/small_hoard.o
NPC_OBJ = NPCs/dragon.o NPCs/dwarf.o NPCs/elf.o NPCs/enemy_character.o NPCs/halfling.o NPCs/human.o NPCs/merchant.o NPCs/orcs.o
PC_OBJ = PCs/drow.o PCs/goblin.o PCs/player_character.o PCs/shade.o PCs/troll.o PCs/vampire.o
POTION_OBJ = potion/boost_attack.o potion/boost_defense.o potion/poison_health.o potion/potion.o potion/restore_health.o potion/wound_attack.o potion/wound_defense.o
OBJECTS = $(MAIN_OBJ) $(FACTORY_OBJ) $(GOLD_OBJ) $(NPC_OBJ) $(PC_OBJ) $(POTION_OBJ)
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
