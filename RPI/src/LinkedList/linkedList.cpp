#include "linkedList.hpp"


LinkedList::List* LinkedList::MakeList(List l, List p){
   
    l = (struct list*)malloc(sizeof(struct list));
    l->prev = l->next = NULL;
    p=l;
    arr[0] = l;
    arr[1] = p;
    return &arr[0];
}

void LinkedList::DeleteElement(List l, int x){
    Position p, p1, p2;
    p = FindElement(l,x);
    if (p != NULL){
        p1 = p->prev;
        p2 = p->next;
        p1->next = p->next;
        if(p2 != NULL){
            p2->prev = p->prev;
        }else{
            std::cout << "Element does not exist" <<std::endl;
        }
    }else
        std::cout << "Element does not exist" <<std::endl;

   
}
LinkedList::List LinkedList::FindElement(List l, int x){
    Position p = l->next;
    while(p->id != x){
        p = p->next;
        if(p == NULL){
            return NULL;
        }
    }
    return p;
}
void LinkedList::AddElement(List l, Position p, char* name,int dis, bool esta, float time){
    p=l;
    int pos = curID;
    for(int i= 1;i< pos;i++)
        p = p->next;
    Position tempNode;
    tempNode = (struct list*)malloc(sizeof(struct list));
    if(tempNode == NULL){
        std::cout << "error: no mem" << std::endl;
        exit(0);
    }else{
        tempNode->id = curID;
        strcpy(tempNode->name, name);
        tempNode->distance = dis;
        tempNode->estafette = esta;
        tempNode->time = time;

        tempNode->next = p->next;
        tempNode->prev = p;
        p->next = tempNode;
        curID = curID+1;
    }
}
void LinkedList::PrintElement(List l){
    Position p = l->next;
    while(p != NULL){
        std::cout << p->id << ":" << p->name << ":" << \
            "distance:"<< p->distance <<": estafette: " <<
            p->estafette << " :time: " << p->time << std::endl;
        p = p->next;
    }
}

void LinkedList::SaveLinkedList(List l){
    Position p;
    p = l->next;
    fptr = fopen(fileName, "w");
    if(fptr == NULL){
        std::cout << "error, cant open file" << std::endl;
        exit(0);
    }else{
        while(p != NULL){

            fprintf(fptr, "%d,\n%s,\n%d,\n%x,\n%.2f\n\n", \
                p->id, p->name, p->distance, p->estafette, p->time);
            p = p->next;
        }
    }

}

void LinkedList::SetFileName(char* fn){
    strcpy(fileName, fn);
}