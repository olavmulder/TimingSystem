#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node {
  float time;
  unsigned int id;
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

struct Node* AddItem(struct Node *l, float t, unsigned int i){
 Serial.println("addItem");
 Node* dum;
 dum = (struct Node*)malloc(sizeof(struct Node));
 Serial.println("malloc dum");
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
String PrintList(String s){
  Serial.println("PrintList");
  struct Node *n;
  n = (struct Node*)malloc(sizeof(struct Node));
  n = head;
  Serial.println("list::");
  while(n != NULL){
    s = String(s + String(n->id) + ": " + String(n->time,3) + "\n");
    Serial.println("String V");
    Serial.print(n->id);
    Serial.print(" ");
    Serial.println(n->time);
    n = n->next;
  }
  Serial.println("end print list");
  return s;
}
#endif
