#include<iostream>
using namespace std;
#include <string>
#include <algorithm>

int main(){
    string s1;
    getline(cin,s1);
    sort(s1.begin(),s1.end());
    string s2;
    for(int i=s1.length();i>0;i--){
        s2=s2+s1[i];
        

    }
    cout<<s2<<endl;
    return 0;

}