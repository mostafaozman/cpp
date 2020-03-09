#include <iostream>
#include <cstring>
#include "room.h"

using namespace std; 

Room::Room()
{

}

char* Room::getDes() // Getter for room description
{ 
  return des; 
}

int Room::getID() // Getter for room ID
{
  return id; 
}

map<int, char*>* Room::getExit() // Getter for room exits
{
  return &exit; 
}

int Room::getItem() // Getter for Item in the room
{
  return item; 
}

void Room::setDes(char* inpDes) // Setter for room description
{
  des = inpDes; 
}

void Room::setID(int inpID) // Setter for room ID
{
  id = inpID; 
}

void Room::setExit(map<int, char*> inpExit) // Setter for room exits
{
  exit = inpExit; 
}

void Room::setItem(int inpItem) // Setter  for item in room
{
  item = inpItem; 
}
