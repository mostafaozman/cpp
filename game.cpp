#include <iostream>
#include <cstring>
#include "game.h" 

using namespace std; 

game:game()
{

}

char* game::getpub()
{
  return pub; 
}

double* game::getrate()
{
  return rate; 
}

char* game::gettitle()
{
  return title; 
}

int* game::getYear()
{
  return year; 
}

