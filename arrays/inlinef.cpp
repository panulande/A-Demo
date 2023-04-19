#include<iostream>
using namespace std;

//inline functions can't be used with static variables.
inline int product(int a, int b){
    return a*b;
}
//we request compiler to make the function inline, if the point is not valid then it will execute it like it ususally does.
//default args to extreme right and compulsory ones to the left
//const keyword restricts the change by the compiler and keeps the given value constant