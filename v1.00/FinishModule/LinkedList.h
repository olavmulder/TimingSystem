#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "users.h"
struct Node {
  float time;
  unsigned int id;//runed by it
  struct Node *next;
};
struct Node *head;

struct Node* MakeList(float t, unsigned int i){
 struct Node *l;
 head =(struct Node*)malloc(sizeof(struct Node));
 l = (struct Node*)malloc(sizeof(struct Node));
 l->next = NULL;
 l->time = t;
 l->id = i;
 head  = l;
 return l;
 
}

struct Node* AddItem(struct Node *l, float t, unsigned int i){;
 Node* dum;
 dum = (struct Node*)malloc(sizeof(struct Node));
 l->next = dum;
 dum->next = NULL;
 dum->time = t;
 dum->id = i;
 l = dum;
 return l;
}
int GetLastId(Node* l){
  return l->id;
}
String PrintList(Users *userClass, String s){
  struct Node *n;
  n = (struct Node*)malloc(sizeof(struct Node));
  n = head;
  while(n != NULL){
    s = String(s + String(userClass->GetUserNameById(n->id)) + ": " + String(n->time,3) + "<br>");
    n = n->next;
  }
  return s;
}
#endif
