#ifndef item_h
#define item_h

#include <iostream>
#include <cstring>
#include <map>

using namespace std; 

class Item
{
 public:
  Item(); 

  char* getName(); // Function for getting name 
  int getID();  // Function for getting ID
  void setName(char*); // Setting name
  void setID(int); // Setting  ID

 private: 
  char* name; // for storing name
  int id; // for storing ID

}; 

#endif
