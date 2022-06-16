.PHONY = all clean
CC = gcc
LINKERFLAG = -lm
EXECUTABLE = linkedList

LIB_PATH := obj/
CFLAGS   := -fPIC -g -pedantic -Wall -Wextra -ggdb3 -Wall -Wconversion -ansi

SOURCES= linkedList.c
OBJECTS=$(patsubst %.c, %.o, $(SOURCES))

all: ${OBJECTS} #${EXECUTABLE}

#${EXECUTABLE}: ${OBJECTS}
#	${CC} ${CFLAGS} -o $@ ${LIB_PATH}*.o

${OBJECTS}: %.o : %.c
	${CC} ${CFLAGS} -c $< 
	mv *.o ${LIB_PATH}

clean:
	rm ${EXECUTABLE} ${LIB_PATH}*.o