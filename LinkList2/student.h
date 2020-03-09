//
//  Student.hpp
//  LL-F
//
//  Created by Mostafa Osman on 1/18/20.
//  Copyright © 2020 Mostafa Osman. All rights reserved.
//

#ifndef Student_h
#define Student_h

#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

class Student
{
public:
    Student();
    ~Student();
    
    char* getFirstName();
    char* getLastName();
    
    int getID();
    void setID(int);
    
    float getGPA();
    void setGPA(float);
    
private:
    char FirstName[20];
    char LastName[20];
    int ID;
    float GPA;
};

#endif /* Student.hpp */
