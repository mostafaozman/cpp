#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

//constructors
Node::Node(Student* newStudent) {
  student = newStudent;
  next = NULL;
}

Node::~Node() {
  //delete &student;
  //next = NULL;
}

//setters
void Node::setStudent(Student* newStudent) {
  student = newStudent;
}

void Node::setNext(Node* newNext) {
  next = newNext;
}

//getters
Student* Node::getStudent() {
  return student;
}

Node* Node::getNext() {
  return next;
}
