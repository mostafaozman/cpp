#include <iostream>
#include <cstring>
#include "item.h"

using namespace std; 

Item::Item() 
{

}

char* Item::getName() // Function for getting name
{
  return name; 
}

int Item::getID() // Function for  getting id for each item
{
  return id; 
}

void Item::setName(char* inpName) // Function for setting name
{
  name = inpName; 
}

void Item::setID(int inpID) //Function  for setting ID
{
  id = inpID; 
}
