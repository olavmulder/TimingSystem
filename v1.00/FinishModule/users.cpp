#include "users.h"
String Users::GetUserNameById(unsigned int id){
  struct UserList *dum = headUserList;
  while(dum->id != id){
    dum = dum->next;
  }
  return dum->name;
}

String Users::User(){
  String s = "All the users:<br>";
  return PrintUserList(s);
}
void Users::SetCurUserID(unsigned int id){
  curUser = id;
}
unsigned int Users::GetCurUserID(){
  return curUser;
}
//linked list imp

    //linked list
struct UserList* Users::GetHead(){
  return headUserList;
}
struct UserList* Users::MakeList(String n){
  struct UserList *l;
  l = (struct UserList*)malloc(sizeof(struct UserList));
  headUserList = (struct UserList*)malloc(sizeof(struct UserList));

  l->next = NULL;
  l->id = userIDCounter = curUser;
  l->name = n;
  headUserList = l;
  return l;
}
struct UserList* Users::AddItem(struct UserList *l,  String n){
  struct UserList* dum;
  dum = (struct UserList*)malloc(sizeof(struct UserList));
  l->next = dum;
  dum->id = ++userIDCounter;
  dum->name = n;
  dum->next = NULL;
  l = dum;
  return l;

}

String Users::PrintUserList(String s){
  struct UserList *n;
  n = (struct UserList*)malloc(sizeof(struct UserList));
  n = headUserList;
  while(n != NULL){
    s = String(s + String(n->id) + ": " + String(n->name) + "<br>");
    n = n->next;
  }
  return s;
}