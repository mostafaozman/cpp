#include <iostream>
#include <cstring>
#include "media.h"
#include "movie.h"

using namespace std;

Movie::Movie() // calls .h file 
{

}

int Movie::getType() // stores  type
{
  return 0;
}

char* Movie::getDirector() // sends director to .h file
{
  return director;
}

int* Movie::getDuration() // sends duration to .h file
{
  return &duration;
}

float* Movie::getRating() // semds rating to .h file
{
  return &rating;
}
