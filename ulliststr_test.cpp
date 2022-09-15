/* Write your test code for the ULListStr in this file */

#include "ulliststr.h"
#include <iostream>
using namespace std;


int main(int argc, char* argv[])
{
  ULListStr dat; 
dat.push_back("7");
//should be 7
dat.push_front("8");
//should be 8 7 
dat.push_back("9");
//should be 8 7 9 
dat.push_front("20"); 
//should be 20 8 7 9 


//test 1: push functions 
cout << "Test 1: " << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << " " << dat.get(3) << endl; 
cout << "Test 1 should return: 20, 8, 7, 9" << endl; 

dat.pop_front(); 
//should be 8,7,9


//test 2: Pop front 
cout << "Test 2: " << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << endl; 
cout << "Test 2 should return: 8, 7, 9" << endl; 


dat.pop_back(); 
//should be 8,7
dat.pop_front();
//should be 7
dat.push_front("21"); 
//should be 21 7
dat.push_front("22"); 
//should be 22 21 7
dat.push_front("24"); 
//should be 24 22 21 7


//Test 3: Pop back, pop front and adding after removing 
cout << "Test 3: " << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << " " << dat.get(3) << endl; 
cout << "Test 3 should return: 24, 22, 21, 7" << endl; 


//Test 4: Checking back
cout << "Test 4: " << dat.back() << endl;
cout << "Test 4 Should return: 7" << endl;  
// should return [7]


//Test 5: Checking front
cout << "Test 5: " << dat.front() << endl; 
cout << "Test 5 Should return: 24" << endl; 
//Should return [24]

cout << "Test 6: " << dat.size() << endl; 
cout << "Test 6: Should return a size of: 4" << endl; 

dat.push_front("15");
//should be 15, 24, 22, 21, 7
dat.push_front("1");  
//should be 1, 15, 24, 22, 21, 7
dat.push_front("2"); 
//should be 2, 1, 15, 24, 22, 21, 7
dat.push_front("3"); 
//should be 3, 2, 1, 15, 24, 22, 21, 7

//Test 7 to check 8 values present 
cout << "Test 7:" << endl; 
for(int i = 0; i < 8; i++){
  cout << dat.get(i) << " "; 
}
cout << endl;
cout << "Test 7: should return 3, 2, 1, 15, 24, 22, 21, 7" << endl; 

dat.push_front("4");
//should be 4, 3, 2, 1, 15, 24, 22, 21, 7
dat.push_front("5");
//should be 5, 4, 3, 2, 1, 15, 24, 22, 21, 7
dat.push_front("6"); 
//should be 6, 5, 4, 3, 2, 1, 15, 24, 22, 21, 7
dat.push_front("7"); 
//should be 7, 6, 5, 4, 3, 2, 1, 15, 24, 22, 21, 7

cout << "Final Test: ";   
for(int i = 0; i < 12; i++){
  cout << dat.get(i) << " "; 
}
cout << endl; 
cout << "Final Test should print 7, 6, 5, 4, 3, 2, 1, 15, 24, 22, 21, 7" << endl; 
cout << "this test shows that size can exceed original size of 10" << endl; 




  return 0; 

  

}
