#include <iostream> 
#include <cstring> 
#include "media.h"
#include "game.h"

using namespace std; 

Media::Media() // calls .h file
{

}

int Media::getType() // sends type to .h
{

  return 0; 
}

int* Media::getYear() // sends year to .h
{

  return &year;
}

char* Media::getTitle() // sends title to .h
{

  return title; 
}
