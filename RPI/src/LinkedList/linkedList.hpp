#ifndef LinkedList_LIB
#define LinkedList_LIB
#include <iostream>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

class LinkedList {
    public:
       
        struct list;
        typedef struct list *PtrList;
        typedef PtrList List;
        typedef PtrList Position; 
        struct list{
            int id;
            char name[20];
            int distance;
            bool estafette;
            float time;
            Position next;
            Position prev;
        };
        
        LinkedList(){
            curID = 1;
        }
        List* MakeList(List l, List p);
        void AddElement(List l, Position p, char* name, \
            int dis, bool esta, float time);
        void DeleteElement(List l, int x);
        List FindElement(List l, int x);
        void PrintElement(List l);

        void SaveLinkedList(List l);
        
        void SetFileName(char* fileName);
    private:
        int curID;
        List arr[2];
        FILE *fptr;
        char* fileName;
        
};
#endif

