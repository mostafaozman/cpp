/*
By: Mostafa Osman, credit to Omar Nassar for explaining method behind it 
Date: 11/10
This program is essentially a data base in which it can store different types of media (music, movies, and games). You can also search for them by title or year as welll as delete them. 

 */

#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstring>
#include "media.h"
#include "game.h"
#include "movie.h"
#include "music.h"

using namespace std;

// all of these initailize the funtion (prototypes). The first one also passes in the type of media
void add(vector<Media*>* media, int type); 
void search(vector<Media*>* media); 
void dele(vector<Media*>* media); 


int main()
{
  vector<Media*> mediaVector; // vector for storing inputs

  char input[10]; //input

  while(true) 
    {
      cout << "What function would you like to activate? (ADD, SEARCH, DELETE, QUIT))" << endl; 
      cin.get(input, 10); 
      cin.clear(); 
      cin.ignore(100000, '\n'); // gets input for what the user wants to do 
      if (strcmp(input, "ADD") == 0)
	{
	  while (true)
	    {
	      cout << "What would you like to add? (MOVIE, MUSIC, or GAME)" << endl; 
	      cin.get(input, 10); 
	      cin.clear(); 
	      cin.ignore(10000, '\n'); // what type of media would the user like to add 
	      if (strcmp(input, "MOVIE") == 0)
		{
		  add(&mediaVector, 0); // These next few are the vector and type
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
      
      // delete and search function with vector
      else if(strcmp(input, "SEARCH") == 0)
	{
	  search(&mediaVector);
	}

      else if (strcmp(input, "DELETE") == 0)
	{
	  dele(&mediaVector); 
	}
      //quit
      else if (strcmp(input, "QUIT") == 0)
	{
	  break; 
	}
      // not a valid input, promts user to try again
      else 
	{
	  cout << "Invalid input, try capitalizing" << endl; 
	}
    }

  return 0;
}


void add(vector<Media*>* media, int type)
{
  char input[100]; 
  int input1; 
  
  if (type == 0) // adding movie 
    {
      Movie* film = new Movie(); 
      // movie entry
      // all different aspects of the movies info
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

  if (type == 2) // if it is a gamw
    {
      Game* gamez = new Game();
      //new game entry
      // all different aspaects of the games info
      cout << "Please enter the games title: \n"  << endl;
      cin.get(gamez -> getTitle(), 100);
      cin.clear();
      cin.ignore(1000000, '\n');
      cout << "Please enter the games release year: \n"  << endl;
      cin >> *gamez -> getYear();
      cin.clear();
      cin.ignore(1000000, '\n');
      cout << "Please enter the games publisher: \n"  << endl;
      cin.get(gamez -> getPub(), 100);
      cin.clear();
      cin.ignore(1000000, '\n');
      cout << "Please enter the games rating: \n"  << endl;
      cin >> *gamez -> getRating();
      cin.clear();
      cin.ignore(1000000, '\n');

      media -> push_back(gamez);
    }


  if (type == 1) // if it is a song
    {
      Music* song = new Music();
      // new music entry
      // all different 
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
      cout << "Please enter the songs publisher: \n"  << endl;
      cin.get (song -> getPub(), 100);
      cin.clear();
      cin.ignore(1000000, '\n');
      media -> push_back(song);
    }
}

void search(vector <Media*>* media) // function for search
{
  bool good; // make sure input is valid
  char input[10]; 
  char title[50]; 
  int year; 

  cout << "What would you like to use to search? (TITLE or YEAR)" << endl; 
  cin.get(input, 10); 
  cin.clear();
  cin.ignore(1000000, '\n');
  // search by title or year  
  if (strcmp(input, "TITLE") == 0)
    {
      cout << "Please input the title: \n" << endl; 
      cin.get(title, 50); 
      cin.clear();
      cin.ignore(1000000, '\n');
      good = true; // input is valid

    }

  else if (strcmp(input, "YEAR") == 0)
    {
      cout << "Please enter the year: \n" << endl; 
      cin >> year; 
      cin.clear();
      cin.ignore(1000000, '\n');
      good = true; // input is valid
    
    }

  else 
    {
      cout << "Invalid input, try capitalizing" << endl;
      good = false; 
    }
  // bad input break loop
  if (good == true) // if input is good
    {
      vector <Media*>::iterator i; 
      for (i = media -> begin(); i != media -> end(); i++)
	{
	  if(strcmp((*i) -> getTitle(), title) == 0 || *(*i) -> getYear() == year)
	    {
	      // Printing different colletions of things based on type
	      if((*i) -> getType() == 0) // If it is a movie 
		{
		  cout << "Search Movie" << endl; 
		  cout << "Title: " << (*i) -> getTitle() << endl;
		  cout << "Year: " << *(*i) -> getYear() << endl;
		  cout << "Director: " << dynamic_cast<Movie*>(*i) -> getDirector() << endl;
		  cout << "Duration: " << *dynamic_cast<Movie*>(*i) -> getDuration() << endl;
		  cout << "Rating: " << *dynamic_cast<Movie*>(*i) -> getRating() << endl << endl;
		}
	      else if((*i) -> getType() == 1) // If it is a game
		{
		  cout << "Seach Game" << endl; 
		  cout << "Title: " << (*i) -> getTitle() << endl;
		  cout << "Year: " << *(*i) -> getYear() << endl;
		  cout << "Publisher: " << dynamic_cast<Game*>(*i) -> getPub() << endl;
		  cout << "Rating: " << *dynamic_cast<Game*>(*i) -> getRating() << endl << endl;
		}
	      else if((*i) -> getType() == 2) // If it is a song
		{
		  cout << "Search Music" << endl;
		  cout << "Title: " << (*i) -> getTitle() << endl;
		  cout << "Year: " << *(*i) -> getYear() << endl;
		  cout << "Artist: " << dynamic_cast<Music*>(*i) -> getArtist() << endl;
		  cout << "Duration: " << *dynamic_cast<Music*>(*i) -> getDuration() << endl;
		  cout << "Publisher: " << dynamic_cast<Music*>(*i) -> getPub() << endl << endl;
		}
	    }
	}
    }
}

void dele(vector <Media*>* media)
{
  char input1; 
  // Same method as search
  bool good; // make sure input is valid                                                               
  char input[10];
  char title[50];
  int year;
  cout << "What would you like to use to delete? (TITLE or YEAR)" << endl;
  cin.get(input, 10);
  cin.clear();
  cin.ignore(1000000, '\n');

  if (strcmp(input, "TITLE") == 0)
    {
      cout << "Please input the title: \n" << endl;
      cin.get(title, 50);
      cin.clear();
      cin.ignore(1000000, '\n');
      good = true;

    }

  else if (strcmp(input, "YEAR") == 0)
    {
      cout << "Please enter the year: \n" << endl;
      cin >> year;
      cin.clear();
      cin.ignore(1000000, '\n');
      good = true;

    }

  else
    {
      cout << "Invalid input, try capitalizing" << endl;
      good = false;
    }

  if (good == true)
    {
      vector <Media*>::iterator i;
      for (i = media -> begin(); i != media -> end(); i++)
        {
          if(strcmp((*i) -> getTitle(), title) == 0 || *(*i) -> getYear() == year)
            {
              // Printing different colletions of things based on type                                 
              if((*i) -> getType() == 0) // If it is a movie                                           
                {
                  cout << "Search Movie" << endl;
                  cout << "Title: " << (*i) -> getTitle() << endl;
                  cout << "Year: " << *(*i) -> getYear() << endl;
                  cout << "Director: " << dynamic_cast<Movie*>(*i) -> getDirector() << endl;
                  cout << "Duration: " << *dynamic_cast<Movie*>(*i) -> getDuration() << endl;
                  cout << "Rating: " << *dynamic_cast<Movie*>(*i) -> getRating() << endl << endl;
		  
		  cout << "Are you sure you would like to delete this? (y/n)" << endl; 
		  cin >> input1; 
		  cin.clear(); 
		  cin.ignore(1000000, '\n'); 
		  
		  if (input1 == 'y')
		    {
		      delete *i; // deletes i from memory
		      i = media -> erase(i);  
		      cout << "Deleted" << endl; 
		      i--; // go back one value because it is now shorter
		    }
		  else if (input1 == 'n')
		    {
		      cout << "Entry not deleted" << endl; 
		      
		    }
		  else 
		    {
		      cout << "Invalid input, please try again." << endl; 
		    }
		}
              else if((*i) -> getType() == 1) // If it is a game                                      
                {
                  cout << "Seach Game" << endl;
                  cout << "Title: " << (*i) -> getTitle() << endl;
                  cout << "Year: " << *(*i) -> getYear() << endl;
                  cout << "Publisher: " << dynamic_cast<Game*>(*i) -> getPub() << endl;
                  cout << "Rating: " << *dynamic_cast<Game*>(*i) -> getRating() << endl << endl;
		  
		  cout << "Are you sure you would like to delete this? (y/n)" << endl;
                  cin >> input1;
                  cin.clear();
                  cin.ignore(1000000, '\n');

                  if (input1 =='y')
                    {
		      delete *i; // deletes i from memory                                              
		      i = media-> erase(i);
		      cout << "Deleted"<< endl;
                      i--;
                    }
                  else if (input1 == 'n')
                    {
		      cout << "Entry not deleted" << endl;
		      
                    }
                  else
                    {
		      cout << "Invalid input, please try again." << endl;
                    }
                }
              else if((*i) -> getType() == 2) // If it is a song                                      
                {
                  cout << "Search Music" << endl;
                  cout << "Title: " << (*i) -> getTitle() << endl;
                  cout << "Year: " << *(*i) -> getYear() << endl;
                  cout << "Artist: " << dynamic_cast<Music*>(*i) -> getArtist() << endl;
                  cout << "Duration: " << *dynamic_cast<Music*>(*i) -> getDuration() << endl;
                  cout << "Publisher: " << dynamic_cast<Music*>(*i) -> getPub() << endl << endl;

		  cout << "Are you sure you would like to delete this? (y/n)" << endl;
                  cin >> input1;
                  cin.clear();
                  cin.ignore(1000000, '\n');

                  if (input1 =='y')
                    {
		      delete *i; // deletes i from memory                                              
		      i = media-> erase(i);
		      cout << "Deleted"<< endl;
                      i--;
                    }
                  else if (input1 == 'n')
                    {
		      cout << "Entry not deleted" << endl;
		      
                    }
                  else
                    {
		      cout << "Invalid input, please try again." << endl;
                    }
                }
            }
        }
    }
}
