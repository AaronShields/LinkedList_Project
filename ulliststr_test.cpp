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
cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << " " << dat.get(3) << endl; 
cout << "should return: 20, 8, 7, 9" << endl; 

dat.pop_front(); 
//should be 8,7,9


//test 2: Pop front 
cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << endl; 
cout << "should return: 8, 7, 9" << endl; 


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
cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << " " << dat.get(3) << endl; 
cout << "should return: 24, 22, 21, 7" << endl; 


//Test 4: Checking back
cout << dat.back() << endl;
cout << "Should return: 7" << endl;  
// should return [7]


//Test 5: Checking front
cout << dat.front() << endl; 
cout << "Should return: 24" << endl; 
//Should return [24]

cout << dat.size() << endl; 
cout << "Should return a size of: 4" << endl; 

  return 0; 

}
