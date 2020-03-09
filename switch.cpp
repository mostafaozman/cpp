#include <iostream>
#include <cstring>

using namespace std; 

int main()
{
  char input[51]; 
  char output[51];
  char temp; 

  cout << "Please enter a phrase and this program will switch the first two lwtters of every word" << endl;
  cin.get(input, 51); 
  cin.clear(); 
  cin.ignore(10000, '\n');
  cout << input << '\n'; 

  //cout << strlen(input); 

  for (int i = 0; i  < strlen(input); i++)
    {
      if(input[i] ==  ' ')
	{
	  cout << "found space" << input[i] << input[i+1] << input[i+2] << endl; 
	  output[i] = input[i]; 
	  output[i+1] = input[i+2];
	  output[i+2] = input[i+1]; 
	  cout << "replaced letterse"<< output[i] << output[i+1] << output[i+2] << endl;
	  i+=2; 
	}
      else
	{
	  output[i] = input[i];
	} 
    }
  output[strlen(input)] = '\0'; 

  cout << "Here is the switched input: \n" << endl; 
  cout << output; 
  cout << '\n'; 
  return  0; 
}
