CXX=g++
CXXFLAGS=-std=c++14 -Wall -MMD -g 
OBJECTS=main.o boardPiece.o game.o observer.o ownableProperty.o player.o subject.o textDisplay.o unownableProperty.o
DEPENDS=${OBJECTS:.o=.d}
EXEC=watopoly
${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean
clean:
	rm ${EXEC} ${OBJECTS} ${DEPENDS}
