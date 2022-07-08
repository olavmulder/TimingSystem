#include "users.h"

String Users::User(){
  String s = "All the users:\n";
  return PrintList(s);
}
unsigned int Users::GetCurUserID(){
  return curUser;
}
//linked list imp

    //linked list
struct UserList* Users::MakeList(char* n){
  struct UserList *l;
  l = (struct UserList*)malloc(sizeof(struct UserList));
  headUserList = (struct UserList*)malloc(sizeof(struct UserList));

  l->next = NULL;
  l->id = curUser = 0;
  l->name = n;
  headUserList = l;
  return l;
}
struct UserList* Users::AddItem(struct UserList *l,  char* n){
  struct UserList* dum;
  dum = (struct UserList*)malloc(sizeof(struct UserList));
  l->next = dum;
  dum->id = ++curUser;
  dum->name = n;
  dum->next = NULL;
  l = dum;
  return l;

}
String Users::PrintList(String s){
  struct UserList *n;
  n = (struct UserList*)malloc(sizeof(struct UserList));
  n = headUserList;
  while(n != NULL){
    s = String(s + String(n->id) + ": " + String(n->name) + "\n");
    n = n->next;
  }
  return s;
}