#ifndef media_h
#define media_h
#include <iostream> 
#include <cstring> 

using namespace std; 

class Media
{
 public: 
  Media(); 
  int* getyear(); 
  char* gettitle();
  virtual int gettype(); 
 private: 
  int year; 
  char title[20]; 
}; 

#endif
