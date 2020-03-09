/*
Zuul: A text based game played by taking simple inputs such as directions and actions like "get"
or "drop". The goal of the game is to escape the map
Created by: Mostafa Osman
Date: 11/30

*/
#include <iostream>
#include <cstring>
#include <iomanip>
#include <vector>
#include <map>
#include <algorithm>
#include "room.h"
#include "item.h"

using namespace std;

void initializeRooms(vector<Room*>* rooms);
void initializeItems(vector<Item*>* items);
void printRoom(vector<Room*>* rooms, vector<Item*>* items, int currentRoom);
void printInventory(vector<Item*>* items, vector<int> inventory);
void pickItem(vector<Room*>* rooms, vector<Item*>* items, vector<int>* inventory, int currentRoom, char name[]);
void dropItem(vector<Room*>* rooms, vector<Item*>* items, vector<int>* inventory, int currentRoom, char name[]);
int move(vector<Room*>* rooms, int currentRoom, char direction[]); 


int main()
{
  vector<Room*> rooms; // Vector for storing rooms
  vector<Item*> items; // Storing items
  vector<int> inventory; // Storing inventory
  char input[50];
  int currentRoom = 1;
  initializeItems(&items);
  initializeRooms(&rooms);
  /* cout<<"Printing initialized rooms\n";
  printRoom(&rooms, &items, 1);
  printRoom(&rooms, &items, 2);
  printRoom(&rooms, &items, 3);
  printRoom(&rooms, &items, 4);
  printRoom(&rooms, &items, 5);
  printRoom(&rooms, &items, 6);
  printRoom(&rooms, &items, 7);
  printRoom(&rooms, &items, 8);
  printRoom(&rooms, &items, 9);
  printRoom(&rooms, &items, 10);
  printRoom(&rooms, &items, 11);
  printRoom(&rooms, &items, 12);
  printRoom(&rooms, &items, 13);
  printRoom(&rooms, &items, 14);
  printRoom(&rooms, &items, 15);
  cout<<"\nEndprintimng rooms\n";*/
  cout << "You find yourself in the dark, inside a mansion. You vaguely recall that you may have been at a party of some sorts.  The doors all around the perimiter are locked, can you get out? \n" << endl; 

  cout << "\n" << "type 'help' if you need help" << endl;

  while (true)
    {
      cout << "You are in ";
      printRoom(&rooms, &items, currentRoom);
      cin >> input;
      cin.clear();
      cin.ignore(10000000, '\n');
      if (strcmp(input, "help") == 0)
	{
	  cout << endl << "The goal of the game is to escape the mansion, to do so you may need to collect some items along the way" << endl;
	  cout << "You may move or pick/drop items by using the words: " << endl; 
	    cout << "move, get, drop, inventory, help, and quit." << endl; 
	}
      
      else if(strcmp(input, "quit") == 0)
	{
	  cout << "Thanks for playing! Come back soon!" << endl;
	  break; 
	}
      
      else if(strcmp(input, "move") == 0)
	{
	  cout << endl << "Which direction would you like to go? Please input a cardinal direction\n"; 
	  cin >> input;
	  cin.clear();
	  cin.ignore(10000000, '\n');

	  if(move(&rooms, currentRoom, input) == 0) // If there is no room that matches input
	    {
	      cout << endl << "You cannot go that direction" << endl; 
	    }
	  else
	    {
	      currentRoom = move(&rooms, currentRoom, input);
	    }
	}

      else if(strcmp(input, "inventory") == 0)
	{
	  if (inventory.size() != 0) // If there is something in the inventory
	    {
	      cout << endl << "You have: " << endl;
	      printInventory(&items, inventory);
	    }
	  else // Nothing in the inventory
	    {
	      cout << "You have nothing in your inventory! Try picking something up" << endl; 
	    }
	}

      else if(strcmp(input, "get") == 0)
	{
	  cout << endl << "What would you like to pick up?" << endl;
	  cin.get(input, 50);
	  // cout<<"\nYou want to pickup"<<input;
	  cin.clear();
	  cin.ignore(1000000, '\n');
	  //cout<<"\nYou want to pick up"<<input;
	  pickItem(&rooms, &items, &inventory, currentRoom, input);
	}

      else if(strcmp(input, "drop") == 0)
	{
	  cout << endl << "What would you like to drop?" << endl;
	  cin.get(input, 50);
	  cin.clear();
	  cin.ignore(10000, '\n');
	  dropItem(&rooms, &items, &inventory, currentRoom, input);
	}
      else
	{
	  cout << endl << "Not a valid input. Check your spelling." << endl;  
	}
      // Winning condition
      if ((currentRoom == 15) && (find(inventory.begin(), inventory.end(), 1) != inventory.end())
	  && (find(inventory.begin(), inventory.end(), 3) != inventory.end())
	  && (find(inventory.begin(), inventory.end(), 4) != inventory.end())
	  && (find(inventory.begin(), inventory.end(), 5) != inventory.end()))
	{
	  cout << "In the dark room you screwed in the light bulb so you can see. This then revealed a missing screw in the door lock, after fixing that you then used the key to unlock the door and you escaped! Good Job!" << endl;
	  break; 
	}
    }
  return 0;
}
// method for adding all rooms to vector
void initializeRooms(vector<Room*>* rooms)
{
  char* west = (char*)("west");
  char* east = (char*)("east");
  char* north = (char*)("north");
  char* south = (char*)("south");
  map<int, char*> temp; //temporary map to store exits then make them room exits

  // Lobby
  Room* lobby = new Room();
  lobby -> setDes((char*)("Lobby: The front of the building")); // set description of the room
  lobby -> setID(1); // set room ID
  // set exits
  temp.insert(pair<int, char*> (2, north));
  temp.insert(pair<int, char*> (3, west));
  temp.insert(pair<int, char*> (4, south));
  lobby -> setItem(0); 
  lobby -> setExit(temp); // pushes exits to class
  rooms -> push_back(lobby); // pushes room to the vector
  temp.clear(); //clears the map

   // Closet
  Room* closet = new Room();
  closet -> setDes((char*)("Closet: A little unpleasent smelling and rather small")); // set description of the room            
  closet -> setID(2); // set room ID                                                               
  // set exits                                                                                     
  temp.insert(pair<int, char*> (1, south));
  closet -> setItem(1);
  closet -> setExit(temp); // pushes exits to class                                                
  rooms -> push_back(closet); // pushes room to the vector                                         
  temp.clear(); //clears the map

   // Main Hallway                                                                                
  Room* mHall = new Room();
  mHall -> setDes((char*)("Main Hall: The hallway that runs throughout the mansion")); // set description of the room            
  mHall -> setID(3); // set room ID                                                                
  // set exits                                                                                     
  temp.insert(pair<int, char*> (1, east));
  temp.insert(pair<int, char*> (9, west));
  temp.insert(pair<int, char*> (10, south));
  temp.insert(pair<int, char*> (5, north)); 
  mHall -> setItem(0);
  mHall -> setExit(temp); // pushes exits to class                                                
  rooms -> push_back(mHall); // pushes room to the vector                                          
  temp.clear(); //clears the map

   // Bathroom                     
  Room* bath = new Room();
  bath -> setDes((char*)("Bathroom: The guest bathroom, inside a drawer you find an object")); // set description of the room            
  bath -> setID(4); // set room ID                                                                
  // set exits                                                                                     
  temp.insert(pair<int, char*> (1, north));
  bath  -> setItem(4);
  bath -> setExit(temp); // pushes exits to class                                                 
  rooms -> push_back(bath); // pushes room to the vector                                          
  temp.clear(); //clears the map

   // North Hall                                                                           
  Room* nHall = new Room();
  nHall -> setDes((char*)("North Hall: Runs through the north wing of the bulding")); // set description of the room            
  nHall -> setID(5); // set room ID                                                                
  // set exits                                                                                     
  temp.insert(pair<int, char*> (7, north));
  temp.insert(pair<int, char*> (6, east)); 
  temp.insert(pair<int, char*> (8, west));
  temp.insert(pair<int, char*> (3, south));
  nHall -> setItem(0);
  nHall -> setExit(temp); // pushes exits to class                                                 
  rooms -> push_back(nHall); // pushes room to the vector                                         
  temp.clear(); //clears the map

  // Gym                                                                                    
  Room* gym = new Room();
  gym -> setDes((char*)("The gym: A nice gym with a wide variety of equipment")); // set description of the\
 room                                                                                              
  gym -> setID(6); // set room ID                                                                
  // set exits                                                                                     
  temp.insert(pair<int, char*> (5, west));
  gym -> setItem(0);
  gym -> setExit(temp); // pushes exits to class                                                 
  rooms -> push_back(gym); // pushes room to the vector                                          
  temp.clear(); //clears the map

   // Office                                                                                  
  Room* office = new Room();
  office -> setDes((char*)("The office: Fancy computer, fancy notebooks, fancy pens...")); // set description of theroom                                   
  office -> setID(7); // set room ID                                                               
  // set exits                                                                                     
  temp.insert(pair<int, char*> (5, south));
  office -> setItem(5);
  office -> setExit(temp); // pushes exits to class                                                
  rooms -> push_back(office); // pushes room to the vector                                         
  temp.clear(); //clears the map

   // Theater Room                                                                                
  Room* movie = new Room();
  movie -> setDes((char*)("Theater Room: An array of couches facing an overly large screen")); //set description of the room                                                                     
  movie -> setID(8); // set room ID                                                                
  // set exits                                                                                     
  temp.insert(pair<int, char*> (5, east));
  movie -> setItem(3); 
  movie -> setExit(temp); // pushes exits to class                                                 
  rooms -> push_back(movie); // pushes room to the vector                                          
  temp.clear(); //clears the map

   // Garage 
  Room* garage = new Room();
  garage -> setDes((char*)("The garage: Rolls Royce to Tesla to McLaren")); // set description of theroom                         
  garage -> setID(9); // set room ID                                                    
  // set exits                                                             
  temp.insert(pair<int, char*> (3, east));
  garage -> setItem(0);
  garage -> setExit(temp); // pushes exits to class                                          
  rooms -> push_back(garage); // pushes room to the vector
  temp.clear(); //clears the map

   // South Hall                                                                                   
  Room* sHall = new Room();
  sHall -> setDes((char*)("South Hall: Runs through the south wing of the bulding")); // set description of theroom                                                                                   
  sHall -> setID(10); // set room ID                                                               
  // set exits                                                                                     
  temp.insert(pair<int, char*> (3, north));
  temp.insert(pair<int, char*> (11, east));
  temp.insert(pair<int, char*> (14, west)); 
  sHall -> setItem(0);
  sHall -> setExit(temp); // pushes exits to class                                                 
  rooms -> push_back(sHall); // pushes room to the vector                                          
  temp.clear(); //clears the map

   // Master Bedroom                                                                              
  Room* mBed = new Room();
  mBed -> setDes((char*)("Master Bedroom: Slik sheets and lavish blankets, heaven...")); // set description of the room                                                                              
  mBed -> setID(11); // set room ID                                                                
  // set exits                                                                                     
  temp.insert(pair<int, char*> (12, north));
  temp.insert(pair<int, char*> (13, east));
  temp.insert(pair<int, char*> (10, west));
  mBed -> setItem(0);
  mBed -> setExit(temp); // pushes exits to class                                                 
  rooms -> push_back(mBed); // pushes room to the vector                                          
  temp.clear(); //clears the map

   // Walk in closet                                                                               
  Room* clothCloset = new Room();
  clothCloset -> setDes((char*)("Walk in Closet: Closet for the master bedroom. Louis Vuitton and Versace and Tom Ford, it really is a masterpiece.")); // set description of theroom                
  clothCloset -> setID(12); // set room ID                                                               
  // set exits                                                                                     
  temp.insert(pair<int, char*> (11, south));
  clothCloset -> setItem(2);
  clothCloset -> setExit(temp); // pushes exits to class                                           
  rooms -> push_back(clothCloset); // pushes room to the vector                                   
  temp.clear(); //clears the map

   // Master Bathroom                                                                              
  Room* mBath = new Room();
  mBath -> setDes((char*)("Master Bathroom: Hot tub and sauna and a steamroom....I cant anymore")); // set description of the room                                                                  
  mBath -> setID(13); // set room ID                                                               
  // set exits                                                                                     
  temp.insert(pair<int, char*> (11, west)); 
  mBath -> setItem(0);
  mBath -> setExit(temp); // pushes exits to class                                                 
  rooms -> push_back(mBath); // pushes room to the vector                                         
  temp.clear(); //clears the map

  // Mystery Room
  Room* mystery = new Room();
  mystery -> setDes((char*)("???: Its dark and ominous, you cant see anything but you sense there may be a door on the other side."));
 // set description of the room
  mystery -> setID(14); // set room ID                                                      
  // set exits                   
  temp.insert(pair<int, char*> (15, west));
  temp.insert(pair<int, char*> (10, east)); 
  mystery -> setItem(0);
  mystery -> setExit(temp); // pushes exits to class                                          
  rooms -> push_back(mystery); // pushes room to the vector
  temp.clear(); //clears the map

  // End                                                                              
  Room* gg = new Room();
  gg -> setDes((char*)("The ENDD: Alas! Youve made it to the end and found your way out, or maybee it wouldve been better to say inside..."));
 // set description of the room                              
  gg -> setID(15); // set room ID                                                               
  // set exits                                                                                     
  temp.insert(pair<int, char*> (14, east));
  gg -> setItem(0);
  gg -> setExit(temp); // pushes exits to class                                                 
  rooms -> push_back(gg); // pushes room to the vector     
  temp.clear(); //clears the map 
}

void initializeItems(vector<Item*>* items)
{
  // key
  Item* key = new Item();
  key -> setName((char*)("Janitor Key"));
  key -> setID(1);
  items -> push_back(key);
  //coins
  Item* coin = new Item();
  coin -> setName((char*)("Two Quarters"));
  coin -> setID(2);
  items -> push_back(coin);
  //Screw
  Item* screw = new Item();
  screw -> setName((char*)("Half inch screw"));
  screw -> setID(3);
  items	-> push_back(screw);
  // light bulb
  Item* light = new Item();
  light -> setName((char*)("LED light bulb"));
  light -> setID(4);
  items	-> push_back(light);
  // Screw Driver
  Item* driver = new Item();
  driver -> setName((char*)("Screw Driver"));
  driver -> setID(5);
  items -> push_back(driver); 
}

void printRoom(vector<Room*>* rooms, vector<Item*>* items, int currentRoom)
{ // Printing the rooms themselves, its items, and exits
  vector<Room*>::iterator i;
  vector<Item*>::iterator j;

  for ( i = rooms -> begin(); i != rooms -> end(); i++)
    {
      if (currentRoom == (*i) -> getID())
	{
	  cout << (*i) -> getDes() << "." << endl;
	  cout << "Your exits are: ";
	  for (map<int, char*>::const_iterator v = (*i) -> getExit() -> begin(); v != (*i) -> getExit() -> end(); v++)
	    {
	      cout << v -> second << " "; 
	    }
	  cout << endl;
	  cout << "In this room there are: " << endl;
	   for (j = items -> begin(); j != items -> end(); j++)
	     {
	     if ((*i) -> getItem() == (*j) -> getID())
	       {//printing item in the room
		 cout << (*j) -> getName() << endl;
	       }
	   }
	  cout << endl;
	  break; 
	}
    }
}

void printInventory(vector<Item*>* items, vector<int> inventory)
{
  vector<int>::iterator i;
  vector<Item*>::iterator j;

  for (i = inventory.begin(); i != inventory.end(); i++)
    {
      for (j = items -> begin(); j != items -> end(); j++)
	{
	  if( *i == (*j) -> getID())
	    {
	      cout << (*j) -> getName() << endl; 
	    }
	}
    }
  cout << endl; 

}

void pickItem(vector<Room*>* rooms, vector<Item*>* items, vector<int>* inventory, int currentRoom, char name[])
{
  vector<Room*>::iterator i;
  vector<Item*>::iterator j;
  
  for (i = rooms -> begin(); i != rooms -> end(); i++)
  {
    if (currentRoom == (*i) -> getID())
  	{
	  cout<<"\nroomid = "<<(*i) -> getID();
	  for (j = items -> begin(); j != items -> end(); j++)
	    {
	      /*  cout<<"\nitem is\n"<<(*i) -> getItem();
	      cout<<"j item id is"<<(*j) -> getID();
	      cout<<"\n name = "<<name;
	      cout<<"\n j name ="<<(*j)->getName();*/
	      if (((*i) -> getItem() == (*j) -> getID()) && (strcmp((*j) -> getName(), name) == 0))
		{
		  cout<<"\nI am picking up the item\n";
		  inventory -> push_back((*j) -> getID());
		  (*i) -> setItem(0);
		  cout << endl << "You picked up " << (*j) -> getName() << "." << endl;
		  return; 
		}
	    }
	}
    }

  cout << endl << "The item you are looking for is not here" << endl << endl; 

}

void dropItem(vector<Room*>* rooms, vector<Item*>* items, vector<int>* inventory, int currentRoom, char name[])
{
  int count;
  vector<Room*>::iterator i;
  vector<Item*>::iterator j;
  vector<int>::iterator z;

  for (i = rooms -> begin(); i != rooms -> end(); i++)
    {
      if (currentRoom == (*i) -> getID())
	{
	  if ((*i) -> getItem() == 0)
	    {
	      for ( j = items -> begin(); j != items -> end(); j++)
		{
		  if ((strcmp((*j) -> getName(), name) == 0))
		    {
		      for( z = inventory -> begin(); z != inventory -> end(); z++)
			{
			  if ((*z) == (*j) -> getID())
			    {
			      cout << endl << "You dropped: " << (*j) -> getName() << endl << endl;
			      (*i) -> setItem((*j) -> getID());
			      z = inventory -> erase(z);
			      return; 
			    }
			}
		    }

		  else if (count == items -> size() - 1)
		    {
		      cout << endl << "This item is not currently in your inventory" << endl;
		      
		    }
		  count++; 
		}
	    }

	  else
	    {
	      cout << "This item has already been dropped here" << endl; 
	    }
	}
    }
      cout << endl; 

}

int move(vector<Room*>* rooms, int currentRoom, char direction[])
{
  vector<Room*>::iterator i; 
  
  for( i = rooms -> begin(); i != rooms -> end(); i++)
    {
      if (currentRoom == (*i) -> getID())
	{
	  map <int, char*> exit;
	  exit = *(*i) -> getExit();
	  map<int, char*>::const_iterator z;
	  for(z = exit.begin(); z != exit.end(); z++)
	    {
	      if (strcmp(z -> second, direction) == 0)
		{
		  return z -> first; 
		}
	    }
	}
    }

  return 0; 

}
