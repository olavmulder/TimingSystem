.PHONY = all clean addUser 
CC = g++
LINKERFLAG = -lm
EXECUTABLE = mainTimingSystem
LIB_PATH := ../obj/
CFLAGS   := -std=c++11 -g -pedantic -Wall -Wextra -Wall -Wconversion -ansi

SOURCES := timing.cpp socket.cpp mainProgram.cpp gpio.cpp
OBJECTS =$(patsubst %.cpp, %.o, $(SOURCES))

all: ${EXECUTABLE}
	mv ${EXECUTABLE} ../bin
${EXECUTABLE}: ${OBJECTS}
	${CC} ${CFLAGS} -o $@ ${LIB_PATH}*.o

${OBJECTS}: %.o : %.cpp
	${CC} ${CFLAGS} -c $< 
	mv *.o ${LIB_PATH}

addUser: addUser.cpp
	${CC} ${CFLAGS} -o $@ $^
	mv addUser ../bin/
clean:
	rm ${EXECUTABLE} ${LIB_PATH}*.o ../bin/addUser