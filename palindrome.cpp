/*
By: Mostafa Osman
This is a plindrome checker, it removes special characters, spaces, and converts to lowercase
9/19/19
 */
#include <iostream>
#include <cstring> 

using namespace std;
int main() 
{
  int z = 0; 
  int a = 0;
  int m = 0; 
  char input[81];  

  cout << "This is a palindrome checker, please enter a palindrome. " << endl;
  cin.get(input, 81); 
  cin.get();
  cout <<"Strlen(input) = " << strlen(input)<< endl;
  for (int i = 0; i <= strlen(input); i++)
      {
	if (isalnum(input[i]))
	  {  
	    z++;
	  }
      }
  cout<<"z = "<<z<<endl;
  char newInput[z];
  
//check for special charcaters and take them out
  //Make everything lower case
  // We need a newIndex for the newInput array as we are skipping array elements from the original input array
  int newIndex = 0;
  for (int i = 0; i < strlen(input); i ++) 
    {
    if (isalnum(input[i]))
      {
	if (input[i] >= 65 && input[i] <= 90)
	  {
	    input[i] += 32; 
	  }
	newInput[newIndex] = input[i];
	cout << "newInput = "<<newInput[newIndex] << endl;
	newIndex++;
      }
    }
  
  //Reverse the input
  char revInput[z]; 
  for (int i = z-1; i>= 0; i--)
    {
      revInput[i] = newInput[z-i-1]; 
    } 

  //Print the reversed input
  for ( int b = 0; b < z; b++)
    {
      cout <<"revInput ="<<revInput[b] << endl; 
    }

  for (int b = 0; b < z; b++)
    {
      if (revInput[b] == newInput[b])
	{
	  m++; 
	}
	else
	  {
	  }
    }
  // Checks for palindrome by comparing number of matching characters 
      if (m == z)
	{
	  cout << "This is a Palindrome!" << endl;
	}
      else
	{
	  cout << "This is not a Palindrome!";
	}
  return 0; 
}
