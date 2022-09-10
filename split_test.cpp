

#include "split.h"
#include <cstddef>
#include <iostream>
using namespace std; 

//append steps through list and adds the term onto the end 
void append(Node *&head, const int n)
{
    if(head == NULL){
        head = new Node(n, NULL);   
    }
    else{
        append(head->next, n);
    }
  }

//this function just splits my values 
/*void split(Node *&in, Node *&evens, Node *&odds)
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
*/
void traverse (Node *&head)
{
    if(!head){
        head = NULL;
        return; 
    }
    else{
    cout << head->value << endl; 
    traverse (head->next);
    }
}




int main()
{
  Node *head = NULL; 
  Node *evens = NULL; 
  Node *odds = NULL; 
  append(*&head, 6); 
  append(*&head, 5);
  append(*&head, 9);
  append(*&head, 12);
  append(*&head, 14);
  append(*&head, 13); 
  split(*&head, *&evens, *&odds); 
  traverse(*&evens); 
  traverse(*&odds); 
  head = odds; 
  while(head != NULL){
    Node *temp = NULL; 
    temp = head;
    head = head->next;  
    delete temp; 
  }
  head = evens;  
  while(head != NULL){
    Node *temp = NULL; 
    temp = head;
    head = head->next;  
    delete temp; 
  }

   delete head; 

   return 0; 
}
  

