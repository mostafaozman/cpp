#ifndef NODE_H
#define NODE_H

#include "student.h"

using namespace std;

class Node {
 public:
  Node(Student*);
  ~Node();
  //setters
  void setStudent(Student*);
  void setNext(Node*);
  //getters
  Student* getStudent();
  Node* getNext();
 private:
  //variables
  Student* student;
  Node* next;
};
#endif
