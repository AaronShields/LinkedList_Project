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
#include <iostream>
using namespace std; 


//split checks if the head exists, if it does then it checks if the value exists
//if value is even, value is transferred to even pointer and recursion is called on nextptrs of even and odd
//same with odd
void split(Node *&in, Node *&evens, Node *&odds)
{
    Node* current = in;
    if(!current){
        evens = NULL; 
        odds = NULL; 
        return; 
    }
    else if(current->value % 2 == 0){
        evens = current; 
        //cout << evens-> value << endl; 
        split(in->next, evens->next, odds);
    }
    else{
        odds = current; 
        //cout << evens-> value << endl; 
        split(in->next, evens, odds->next);

    }
}
//traverse just checks to see if values of linked list exist

