#include "linkedList.h"
List arr[2];
List* MakeList(List l, List p){
    l = (struct list*)malloc(sizeof(struct list));
    l->prev = l->next = NULL;
    p=l;
    arr[0] = l;
    arr[1] = p;
    return &arr[0];
}


void AddElement(List list, Position p, char* name, float time){
    Position tempNode;
    tempNode = (struct list*)malloc(sizeof(struct list));
    if(tempNode == NULL){
        printf("error: no mem");
        exit(0);
    }else{
        tempNode->time = time;
        strcpy(tempNode->name, name);
        tempNode->next = p->next;
        tempNode->prev = p;
        p->next = tempNode;
        p=list;
    }

}
void PrintElement(List l){
    Position p = l->next;
    while(p != NULL){
        printf("%s:%f\n", p->name,p->time);
        p = p->next;
    }
}