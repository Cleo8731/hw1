/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>

void splitHelper(Node*&, Node*&, Node*&);

void split(Node*& in, Node*& odds, Node*& evens)
{
  odds = new Node(0, nullptr);
  evens = new Node(0, nullptr);
  splitHelper(in, odds, evens);

  Node* temp = odds;
  odds = odds->next;
  delete temp;
  temp = evens;
  evens = evens->next;
  delete temp;

  in = NULL;
}

// Helper function for split
void splitHelper(Node*& in, Node*& odds, Node*& evens)
{
  if (in == nullptr)
  {
    evens->next = nullptr;
    odds->next = nullptr;
    return;
  }
  else if (in->value % 2 == 0) // even
  {
    evens->next = in;
    splitHelper(in->next, odds, evens->next);
  }
  else if (in->value % 2 == 1) // odd
  {
    odds->next = in;
    splitHelper(in->next, odds->next, evens);
  }
}