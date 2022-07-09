#ifndef USERS_H
#define USERS_H
#include "Arduino.h"
struct UserList{
  unsigned int id;
  String name;  
  struct UserList *next;
};
class Users{
  private:
    UserList *headUserList;
    unsigned int curUser;
    unsigned int userIDCounter;

  public:
    Users(){
      curUser = 0;
      userIDCounter = 0;
    }
   
    String User();
    unsigned int GetCurUserID();
    void SetCurUserID(unsigned int);

    //linked list
    struct UserList* GetHead();
    struct UserList* MakeList(String name);
    struct UserList* AddItem(struct UserList *l,  String name);
    String PrintUserList(String s);
    String GetUserNameById(unsigned int id);
};


#endif