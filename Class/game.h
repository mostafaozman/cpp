#ifndef game_h
#define game_h
#include <iostream> 
#include <cstring>
#include "media.h" 

using namespace std; 

class Game : public Media // game is a child class of media
{
 public:
  Game(); 
  virtual int getType(); // sorting typr
  char* getPub();  // pointer to publisher
  float* getRating(); // pointer to rating

 private:  
  char pub[100]; 
  float rate;
};

#endif
