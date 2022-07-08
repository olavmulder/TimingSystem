#ifndef TIMING
#define TIMING


class Timing{
  private: 
    unsigned long time;
    unsigned long startTime;
    String timeString;
    bool running;
  public:
    inline void Start(){
      startTime = millis();
    }
    inline void Stop(){
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
