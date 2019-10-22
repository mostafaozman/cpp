#include <iostream> 
#include <cstdlib>
#include <iomanip>
#include <iterator>
#include <vector> 
#include <string.h>

using namespace std; 

struct Student
{
  char FirstName[10];
  char LastName[10]; 
  int id; 
  float gpa; 
};

void Print(vector<Student*> pstudent); 
Student* ADD();
void Delete(vector<Student*>* pstudent, int deleteid);    

int main()
{
  char input[7]; 
  Student Mo; 
  int i = 1; 
  int deleteid; 
  vector<Student*> pstudent; 

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

  else if ((!(strcmp(input, "ADD") == 0)) || (!(strcmp(input, "PRINT") == 0)) || (!(strcmp(input, "DELETE") == 0)))
    {
      cout << "\nPlease enter a vaild command it is case sensitive"<< endl; 
    }
    }

  return 0; 
}

void Print(vector<Student*> pstudent)
{
  cout << "Print Function\n";

  vector<Student*>::iterator ptr;

  for (ptr = pstudent.begin(); ptr <  pstudent.end(); ++ptr)
    {
      cout << (*ptr) -> FirstName << " " << (*ptr) -> LastName << ", " <<
	(*ptr) -> id << ", " << fixed << setprecision(2)<< (*ptr) -> gpa << endl;
    }
  cin.ignore(1000000, '\n'); 
}

Student* ADD()
{
  Student* pupil = new Student();

  cout << "Please enter the students first name: \n"  << endl;
  cin >> pupil->FirstName;
  cout << "Please enter the students last name: \n" << endl;
  cin >> pupil->LastName;
  cout << "Please enter the students ID: \n" << endl;
  cin >> pupil->id;
  cout << "Please enter the students GPA: \n" << endl;
  cin >> pupil->gpa;

  /* cout << "\nYou entered:" << endl;
  cout << pstudent -> FirstName << "\n";
  cout << pstudent -> LastName << "\n";
  cout << "ID: " << pstudent -> id << "\n";
  cout << "GPA: " << fixed << setprecision(2) << pstudent -> gpa << "\n";
  */
  return pupil; 
}

void Delete (vector<Student*>* pstudent, int deleteid)
{
  vector<Student*>::iterator a; 
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