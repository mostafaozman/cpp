#ifndef movie_h
#define movie_h

#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class Movie : public Media {//movie is a child of media
 public:
  Movie();
  virtual int getType(); //storing type
  char* getDirector(); //pointing to director
  int* getDuration(); //pointing to duration
  float* getRating(); //pointing to rating
 private:
  char director[50]; //storing director 
  int duration; //storing duration
  float rating; //storing rating
};

#endif
