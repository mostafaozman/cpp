#include <iostream>
#include <cstring>
#include "media.h"
#include "game.h" 

using namespace std; 

Game::Game() // calls .h file 
{
}

int Game::getType() // sends type to .h  
{
  return 1;
}

char* Game::getPub() // sends publisher to .h 
{
  return pub; 
}

float* Game::getRating() // sneds rating to .h
{
  return &rate; 
}

