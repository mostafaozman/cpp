#ifndef media_h
#define media_h
#include <iostream> 
#include <cstring> 

using namespace std; 

class Media
{
 public: 
  Media(); 
  int* getYear(); // points to year 
  char* getTitle(); // points to title
  virtual int getType(); // sorting type
 private: 
  int year; // sorting year
  char title[20]; // sorting title
}; 

#endif
