#ifndef TIMER
#define TIMER


class Timer{
  private:
    unsigned long start, stop;
  public:
    inline void StartTime(){
      start = millis();
    }
    inline void StopTime(){
      stop = millis();
    }
    inline unsigned long GetTime(){
     
      return stop-start;
    }


};
#endif