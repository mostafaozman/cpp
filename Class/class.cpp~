#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstring>
#include "media.h"
#include "game.h"
#include "movie.h"
#include "music.h"

using namespace std;

void add(vector<Media*>* media, int type); 
void search(vector<Media*>* media); 
void erase(vector<Media*>* media); 


int main()
{
  vector<Media*> mediaVector; 

  char input[10]; //input
  while(true)
    {
      cout << "What function would you like to activate? (ADD, SEARCH, DELETE, QUIT))" << endl; 
      cin.get(input, 10); 
      cin.clear(); 
      cin.ignore(100000, '\n'); 
      if (strcmp(input, "ADD") == 0)
	{
	  while (true)
	    {
	      cout << "What would you like to add? (MOVIE, MUSIC, or GAME)" << endl; 
	      cin.get(input, 10); 
	      cin.clear(); 
	      cin.ignore(10000, '\n'); 
	      if (strcmp(input, "MOVIE") == 0)
		{
		  add(&mediaVector, 0); 
		  break; 
		}
	      else if (strcmp(input, "MUSIC") == 0)
		{
		  add(&mediaVector, 1); 
		  break; 
		}
	      else if (strcmp(input, "GAME") == 0)
		{
		  add(&mediaVector, 2); 
		  break; 
		}
	      else
		{
		  cout << "Invlaid input, try captializing" << endl; 
		}
	    }
	}
    }

  return 0;
}


void add(vector<Media*>* media, int type)
{
  char input[100]; 
  int input1; 
  
  if (type == 0)
    {
      Movie* film = new Movie(); 
      
      cout << "Please enter the movies title: \n"  << endl;
      cin.get(film -> getTitle(), 100);
      cin.clear();
      cin.ignore(1000000, '\n');
      cout << "Please enter the movies release year: \n"  << endl;
      cin >> *film -> getYear(); 
      cin.clear();
      cin.ignore(1000000, '\n');
      cout << "Please enter the movies director: \n"  << endl;
      cin.get(film -> getDirector(), 50);
      cin.clear();
      cin.ignore(1000000, '\n');
      cout << "Please enter the movies duration: \n"  << endl;
      cin >> *film -> getDuration(); 
      cin.clear();
      cin.ignore(1000000, '\n');
      cout << "Please enter the movies rating: \n"  << endl;
      cin >> *film -> getRating();
      cin.clear();
      cin.ignore(1000000, '\n');
      media -> push_back(film); 
    }

  if (type == 1)
    {
      Game* gamez = new Game();

      cout << "Please enter the games title: \n"  << endl;
      cin.get(gamez -> getTitle(), 100);
      cin.clear();
      cin.ignore(1000000, '\n');
      cout << "Please enter the games release year: \n"  << endl;
      cin >> *gamez -> getYear();
      cin.clear();
      cin.ignore(1000000, '\n');
      cout << "Please enter the games publisher:: \n"  << endl;
      cin >> *gamez -> getPub();
      cin.clear();
      cin.ignore(1000000, '\n');
      cout << "Please enter the games rating: \n"  << endl;
      cin >> *gamez -> getRating();
      cin.clear();
      cin.ignore(1000000, '\n');

      media -> push_back(gamez);
    }


  if (type == 2)
    {
      Music* song = new Music();

      cout << "Please enter the songs title: \n"  << endl;
      cin.get(song -> getTitle(), 100);
      cin.clear();
      cin.ignore(1000000, '\n');
      cout << "Please enter the songs release year: \n"  << endl;
      cin >> *song -> getYear();
      cin.clear();
      cin.ignore(1000000, '\n');
      cout << "Please enter the songs artist: \n"  << endl;
      cin.get(song -> getArtist(), 50);
      cin.clear();
      cin.ignore(1000000, '\n');
      cout << "Please enter the songs duration: \n"  << endl;
      cin >> *song -> getDuration();
      cin.clear();
      cin.ignore(1000000, '\n');
      cout << "Please enter the songs publisher:: \n"  << endl;
      cin >> *song -> getPub();
      cin.clear();
      cin.ignore(1000000, '\n');
      media -> push_back(song);
    }

}
