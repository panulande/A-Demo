#include<iostream>
using namespace std;

int sum(int a,int b){
    int c=a+b;
    return c;
}
int swap(int a,int b){
    int temp=a;
    int a=b;
    b=temp;
}


int main(){
    cout<<"the sum of four and fivve is"<<sum(4,5);


    return 0;
}
