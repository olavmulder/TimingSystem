.PHONY = all lib clean
CC = g++
LINKERFLAG = -lm
EXECUTABLE = linkedList

LIB_PATH = ../../obj/
CFLAGS   := -std=c++17 -fPIC -g -pedantic -Wall -Wextra -ggdb3 -Wall -Wconversion -ansi

SOURCES= linkedList.cpp
OBJECTS=$(patsubst %.cpp, %.o, $(SOURCES))

all: ${OBJECTS}

${OBJECTS}: %.o : %.cpp
	${CC} ${CFLAGS} -c $< 
	mv *.o ${LIB_PATH}

clean:
	rm ${EXECUTABLE} ${LIB_PATH}*.o