#include <iostream> 
#include <cstring> 
#include "media.h"

using namespace std; 

Media::Media() // calls .h file
{

}

int Media::gettype() // sending type to .h
{

  return 0; 
}

int* Media::getyear() // sending year to .h
{

  return &year;
}

char* Media::gettitle() // sending title to .h
{

  return title; 
}
