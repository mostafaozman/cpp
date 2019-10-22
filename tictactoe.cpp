/*
 TICTACTOE - This is a console played tictactoe, this will keep track of wins and turns
 To play enter a character followed by a number such as "a1"
 By: Mostafa Osman
 October 2, 2019
 */
#include <iostream>
#include <cstdlib>

using namespace std;

void draw(char* Ptr); 
void clear(char* Ptr);
bool checktie(char* Ptr);
bool checkwin(char* Ptr, bool player);  
 

int main ()
{
  //variable to switch players, false is player1 (X), true is player2 (O)
  bool player = false;
  char board[3][3];
  char pos[2]; 
  char playx = 'X';
  char playo = 'O';
  int Xwins = 0;
  int Owins = 0;
  //Condition to continue playing
  bool playing = true; 

  //intializing board
  for (int x = 0; x < 3; x++)
    {
      for (int y = 0; y < 3; y++)
	{
	  // board[x][y] = &board[x][y];
	  board[x][y] = ' ';
	}
    }
  //draw((char *)board);

  cout << "Welcome to TicTacToe, this is a two player game. Please take turns inputting a position" << endl; 
  
  while (playing)
    {
      cout << "X wins = "<< Xwins << ", O wins = "<< Owins << endl;
      draw((char *) board);
      if (!player)
	cout <<"Turn is X" <<endl;
      else
	cout << "Turn is O"<< endl;
      cout << "Please enter a character followed by a number to place your character" <<endl;
      cout<< "enter qq to quit anytime"<<endl;
      cin>>pos[0]>>pos[1];
      
      if ((pos[0] == 'q') ||  (pos[0] == 'Q'))
	{
	  playing = false;
	  }

      else{
      if ((pos[0] == 'a' || pos[0] == 'b' || pos[0] == 'c') && 
	     (pos[1] == '1' || pos[1] == '2' || pos[1] == '3') &&
	  (board[(int)pos[0] - 'a'][(int)pos[1] - '1'] == ' '))
	{
	  if (!player) 
	    board[(int)pos[0] - 'a'][(int)pos[1] -'1'] = playx;
	  else
	    board[(int)pos[0] - 'a'][(int)pos[1] - '1'] = playo;
	}
      else
	cout<<"Invalid position"<<endl;
      if(checkwin((char *)board, player))
	{
	  draw((char *) board);
	  if(player)
	    {
	    Owins++;
	    cout << "O Wins!"<< endl;
	    }
	  else
	    {
	    Xwins++;
	    cout<<"X Wins!"<<endl;
	    }
	  clear((char *) board);
	}
      else if (checktie((char *) board))
	{
	  draw((char *) board);
	  cout<<"Its a tie!"<<endl;
	  clear((char *) board);
	}
      //Switch players
      player = !player;
      }
    }

  return 0; 
}

void draw(char* Ptr)
{
  //Column header
  cout << " 1 2 3" << endl;
  //Row headers
  //And populate with array elements
  cout << 'a'; 
  for (int i = 0; i < 3; i++)
    {
      cout << ' ' << *(Ptr+i);
    }   
      cout << endl; 

      cout << 'b'; 
      for (int i = 0; i < 3; i++)
	{
	  cout << ' ' << *(Ptr+i+3);
	}
      cout << endl; 

      cout << 'c'; 
      for (int i = 0; i < 3; i++)
	{
	  cout << ' ' << *(Ptr+6+i);
	}
      cout << endl; 
}

void clear (char* Ptr)
{
  //Replace all array contents with blanks
  for (int x = 0; x < 9; x++)
    {
	  *(Ptr+x) = ' '; 
    }
}
  
bool checktie (char* Ptr)
  {
    //If all cells are full and a win was not detected earlier to end the game, then there is a tie
    for (int x = 0; x < 9; x++)
      {
	  if( *(Ptr+x) == ' ')
	    {
		return false;
            }
      }
    return true;
  }

bool checkwin (char* Ptr, bool player)
  {
    //Is it X or O that we are checking for win
     char gamepiece;
      if(!player)
	gamepiece = 'X';
	else
	  gamepiece = 'O';

      //Check Rows
      for (int i = 0; i < 3; i++)
	{
	  if (*(Ptr+0+i) == gamepiece && *(Ptr+3+i) == gamepiece && *(Ptr+6+i) == gamepiece)
	    {
	      //cout<<"Condition 1"<<endl;
	      return true; 
	    }
	}
      
      //Check colums
      for(int y=0; y<9 ; y=y+3)
	{
	  if (*(Ptr+y+0) == gamepiece && *(Ptr+y+1)== gamepiece && *(Ptr+y+2) == gamepiece)
            {
	      //cout<<"Condition 2"<<endl;
	      return true;
            }
      }

      //Check diagonals
      if (*(Ptr+0) == gamepiece && *(Ptr+4)== gamepiece && *(Ptr+8) == gamepiece)
            {
	      //cout<<"Condition 3"<<endl;
	      return true;
            }
      if (*(Ptr+2) == gamepiece && *(Ptr+4)== gamepiece && *(Ptr+6) == gamepiece)
            {
	      //cout<<"Condition 4"<<endl;
	      return true;
            }
      
      // No win
      return false; 
    }
