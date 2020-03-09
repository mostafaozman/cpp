#include <iostream>
#include <cstring>
#include "media.h"
#include "music.h"

using namespace std;

Music::Music() // calling .h file 
{
}

int Music::getType() // type
{
  return 2;
}

char* Music::getArtist() // sends artist to .h file 
{
  return artist;
}

int* Music::getDuration() // sends duration to .h file
{
  return &duration;
}

char* Music::getPub() // sends publisher to .h file
{
  return pub;
}
