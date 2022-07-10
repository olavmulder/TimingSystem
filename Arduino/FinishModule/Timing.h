#ifndef TIMING_H
#define TIMING_H
#include "Users.h"

struct TimeList {
      float time;
      unsigned int id;
      struct TimeList *next;
    };

class TIMING{
  private: 
    unsigned long time;
    unsigned long startTime;
    String timeString;
    bool running;
    
    USERS *u;
    
  public:
    

    TIMING(USERS* us);
    struct TimeList *head;

    struct TimeList* MakeList(float t, unsigned int i);
    struct TimeList* AddItem(struct TimeList* l, float t, unsigned int i);
    int GetLastId(struct TimeList* l);
    String PrintTimeList(String s, bool html);

    inline void StartTime(){
      startTime = millis();
    }
    inline void StopTime(){
      time = millis()-startTime;
    }
    inline unsigned long GetTime(){
      return time;
    }
    inline void ResetTime(){
      time = 0;
    }
    inline bool GetRunning(){
      return running;
    }
    inline void SetRunning(bool value){
      running = value;
    }
    inline String TimeString(){
      timeString = String( ((double)((time/1000) + ((time%1000)*0.001))) , 3) ;
      return timeString;
    }
  
};

#endif
