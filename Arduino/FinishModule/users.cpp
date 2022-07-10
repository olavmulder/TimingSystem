#include "Users.h"

USERS::USERS(){
  curUser = 0;
  userIDCounter = 0;
}
String USERS::GetUserNameById(unsigned int id){
  struct UserList *dum = headUserList;
  while(dum->id != id){
    dum = dum->next;
  }
  return dum->name;
}

String USERS::User(){
  String s = "All the users:<br>";
  return PrintUserList(s);
}
void USERS::SetCurUserID(unsigned int id){
  curUser = id;
}
unsigned int USERS::GetCurUserID(){
  return curUser;
}
//linked list imp

    //linked list
struct UserList* USERS::GetHead(){
  return headUserList;
}
struct UserList* USERS::MakeList(String n){
  struct UserList *l;
  l = (struct UserList*)malloc(sizeof(struct UserList));
  headUserList = (struct UserList*)malloc(sizeof(struct UserList));

  l->next = NULL;
  l->id = userIDCounter = curUser;
  l->name = n;
  headUserList = l;
  return l;
}
struct UserList* USERS::AddItem(struct UserList *l,  String n){
  struct UserList* dum;
  dum = (struct UserList*)malloc(sizeof(struct UserList));
  l->next = dum;
  dum->id = ++userIDCounter;
  dum->name = n;
  dum->next = NULL;
  l = dum;
  return l;

}

String USERS::PrintUserList(String s){
  struct UserList *n;
  n = (struct UserList*)malloc(sizeof(struct UserList));
  n = headUserList;
  while(n != NULL){
    s = String(s + String(n->id) + ": " + String(n->name) + "<br>");
    n = n->next;
  }
  return s;
}