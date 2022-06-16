#ifndef LinkedList
#define LinkedList
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
struct list;
typedef struct list *PtrList;
typedef PtrList List;
typedef PtrList Position;

struct list{
    char name[20];
    float time;
    Position next;
    Position prev;
};

List* MakeList(List l, List p);
void AddElement(List list, Position p, char* name, float time);

void PrintElement(List l);


#endif