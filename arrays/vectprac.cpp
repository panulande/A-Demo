#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector <int> avec(5,0);
    for(int i=0;i<5;i++){
        
        avec[i]=1;
    }
    for(int j=0;j<5;j++){
        cout<<avec[j]<<endl;
    }
    return 0;
}