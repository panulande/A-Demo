#include<iostream>
using namespace std;
 
 int getbit(int n, int pos){
    return (n&(1<<pos))!=0;
 } 
 int setbit(int n, int pos){
    return ((n|(1<<pos)));
 }
 bool poweroftwo(int n){
   return n & !(n & n-1);
 }
int numberofones(int n ){
   int count =0;
   while(n){
      n=n&(n-1);
      count++;
      
   }
}