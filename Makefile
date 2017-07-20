CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = cc3k
OBJECTS = character.o drow.o elf.o goblin.o halfling.o main.o orcs.o shade.o vampire.o dragon.o dwarf.o enemy_character.o grid.o human.o merchant.o player_character.o troll.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} -g ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
