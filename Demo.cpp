/**
 * Demo file for the exercise on numbers with units
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 * 
 * Edited by Tal Zichlinsky
 * @since 2022-02
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "Matrix.hpp"
using namespace zich;

int main() {
  
  std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
  std::vector<double> arr = {3, 0, 0, 0, 3, 0, 0, 0, 3};
  Matrix a{identity, 3, 3};  // constructor taking a vector and a matrix size
  Matrix b{arr, 3, 3};
cout << a++ << endl;
/*
[1 0 0]
[0 1 0]
[0 0 1]*/
cout << ++a << endl;
/*
[3 2 2]
[2 3 2]
[2 2 3]
*/
cout << a-- << endl;
/*
[3 2 2]
[2 3 2]
[2 2 3]
*/
cout << --a << endl;
/*
[1 0 0]
[0 1 0]
[0 0 1]*/
cout << (-a) << endl;
  /* prints [-1 0 0]
            [0 -1 0]
            [0 0 -1]*/
cout << (+a) << endl;  
/*
[1 0 0]
[0 1 0]
[0 0 1]
*/   
cout << (a+b) << endl;  
/*
[4 0 0]
[0 4 0]
[0 0 4]
*/   

cout << (a-b) << endl;

/*
[-2 0 0]
[0 -2 0]
[0 0 -2]
*/

cout << (a*b) << endl;

/*
[3 0 0]
[0 3 0]
[0 0 3]
*/

a+=b;
cout << (a) << endl;
/*
[4 0 0]
[0 4 0]
[0 0 4]
*/

a-=b;

cout << (a) << endl;

/*
[1 0 0]
[0 1 0]
[0 0 1]
*/

a*=b;

cout << (a) << endl;

/*
[3 0 0]
[0 3 0]
[0 0 3]
*/
cout << (a*3) << endl;
/*
[9 0 0]
[0 9 0]
[0 0 9]
*/
cout << (3*a) << endl;
/*
[9 0 0]
[0 9 0]
[0 0 9]
*/
a *= -3;
cout << (a) << endl;
/*
[-9 0 0]
[0 -9 0]
[0 0 -9]
*/


istringstream is{"[1 1 1 1], [1 1 1 1], [1 1 1 1]\n"};
is >> b;
cout << b << endl;

/*
[1 1 1 1]
[1 1 1 1]
[1 1 1 1]
*/
ostringstream os;
    os << b;
 cout << os.str() << endl;

/*
[1 1 1 1]
[1 1 1 1]
[1 1 1 1]
*/

  
std::vector<double> identity1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
  std::vector<double> arr1 = {3, 0, 0, 0, 3, 0, 0, 0, 3};
  Matrix a1{identity1, 3, 3};  // constructor taking a vector and a matrix size
  Matrix b1{arr1, 3, 3};

cout << (a1<b1) << endl;
//true == 1

cout << (a1>b1) << endl;
//false == 0

cout << (a1>=b1) << endl;
//false == 0

cout << (a1<=b1) << endl;
//true == 1

cout << (a1==b1) << endl;
//false == 0

cout << (a1!=b1) << endl;
//true == 1


  cout << "End of demo!" << endl;
  return 0;
}