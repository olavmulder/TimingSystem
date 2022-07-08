#ifndef USERS_H
#define USERS_H
#include "Arduino.h"
struct UserList{
  unsigned int id;
  char* name;  
  struct UserList *next;
};
class Users{
  private:
    UserList *headUserList;
    unsigned int curUser;

  public:
    

    String User();
    unsigned int GetCurUserID();

    //linked list
    struct UserList* MakeList(char* name);
    struct UserList* AddItem(struct UserList *l,  char* name);
    String PrintList(String s);
};


#endif