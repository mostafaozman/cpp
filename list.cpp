/*
By: Mostafa Osman, Student List: This program will let you add to a list (name, last name, 
gpa, and ID), print all items from the list, and delete items by looking them up with the id 
 */
#include <iostream> 
#include <cstdlib>
#include <iomanip>
#include <iterator>
#include <vector> 
#include <string.h>

using namespace std; 
// Declares struct for student
struct Student
{
  char FirstName[10];
  char LastName[10]; 
  int id; 
  float gpa; 
};
//declares methods
void Print(vector<Student*> pstudent); 
Student* ADD();
void Delete(vector<Student*>* pstudent, int deleteid);    

int main()
{
  char input[7]; 
  Student Mo; 
  int i = 1; 
  int deleteid; 
  // cretes a vector pointer named pstudent
  vector<Student*> pstudent; 
  //main loop
  while (int i = 1)
    {
      cout << "Would you like to ADD, PRINT, or DELETE?" << endl;
      cin >> input;
  if (strcmp(input, "ADD") == 0)
    { 
      cout << "Add function" << endl;
      pstudent.push_back(ADD());
   }
  
  if (strcmp(input, "PRINT") == 0)
    {
      Print(pstudent); 
    }

  if (strcmp(input, "DELETE") == 0)
    {
      cout << "Delete Funtion";
      cout << "\nPlease enter the ID you want to delete\n";

      cin >> deleteid; 
      Delete(&pstudent, deleteid); 
      cout << "\nDeleted." << endl; 
      cin.clear(); 
      cin.ignore(10000000, '\n'); 
    }
  // if input is not ADD, PRINT, or DELETE it promts the user to input again
  else if ((!(strcmp(input, "ADD") == 0)) || (!(strcmp(input, "PRINT") == 0)) || (!(strcmp(input, "DELETE") == 0)))
    {
      cout << "\nPlease enter a vaild command it is case sensitive"<< endl; 
    }
    }

  return 0; 
}
// print method
void Print(vector<Student*> pstudent)
{
  cout << "Print Function\n";

  vector<Student*>::iterator ptr;
  //points to locaton of info and prints each piece 
  for (ptr = pstudent.begin(); ptr <  pstudent.end(); ++ptr)
    {
      cout << (*ptr) -> FirstName << " " << (*ptr) -> LastName << ", " <<
	(*ptr) -> id << ", " << fixed << setprecision(2)<< (*ptr) -> gpa << endl;
    }
  cin.ignore(1000000, '\n'); 
}
// add method
Student* ADD()
{
  // creates student pointer named pupil
  Student* pupil = new Student();

  cout << "Please enter the students first name: \n"  << endl;
  cin >> pupil->FirstName;
  // clear and ignore after each one
  cout << "Please enter the students last name: \n" << endl;
  cin >> pupil->LastName;
  cout << "Please enter the students ID: \n" << endl;
  cin >> pupil->id;
  cin.clear(); 
  cin.ignore(1000000, '\n');
  cout << "Please enter the students GPA: \n" << endl;
  cin >> pupil->gpa;
  cin.clear();
  cin.ignore(1000000, '\n');

  return pupil; 
}
// delete method
void Delete (vector<Student*>* pstudent, int deleteid)
{
  vector<Student*>::iterator a;
  // if the id inputed is the same as the current id in the loop then delete 
  for (a = pstudent -> begin(); a != pstudent -> end(); ++a)
    {
      if ((*a) -> id == deleteid)
	{
	  delete *a; 
	  pstudent -> erase(a);
	  cin.get(); 
	  return; 
	}
    }
}
