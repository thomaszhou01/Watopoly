CXX=g++
CXXFLAGS=-std=c++14 -Wall -MMD -g -Werror=vla
OBJECTS=main.o
DEPENDS=${OBJECTS:.o=.d}
EXEC=a5
${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean
clean:
	rm ${EXEC} ${OBJECTS} ${DEPENDS}
