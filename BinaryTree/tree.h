#ifndef TREE_H
#define TREE_H

using namespace std;

class tree
{
 public:
  tree(char);
  // setters
  void setRight(tree* inRight);
  void setLeft(tree* inLeft);
  void setNext(tree* inNext);
  void setData(char inData);
    
  //getters
  tree* getRight();
  tree* getLeft();
  tree* getNext();
  int getData();
  // all tree pointers
  tree* next;
  tree* left;
  tree* right;
  int data;
};
#endif
