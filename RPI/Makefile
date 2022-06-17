.PHONY = all clean
CC = gcc
LINKERFLAG = -lm
EXECUTABLE = mainTimingSystem
LIB_PATH := obj/
CFLAGS   := -fPIC -g -pedantic -Wall -Wextra -ggdb3 -Wall -Wconversion -ansi

SOURCES := timing.cpp socket.cpp dataProcessing.cpp mainProgram.cpp
OBJECTS =$(patsubst %.cpp, %.o, $(SOURCES))

all: ${EXECUTABLE}

${EXECUTABLE}: ${OBJECTS}
	${CC} ${CFLAGS} -o $@ ${LIB_PATH}*.o

${OBJECTS}: %.o : %.cpp
	${CC} ${CFLAGS} -c $< 
	mv *.o ${LIB_PATH}

clean:
	rm ${EXECUTABLE} ${LIB_PATH}*.o