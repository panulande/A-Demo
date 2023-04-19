#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
     int n,q;
     
     cin>> n>>q;
     vector<vector <int>> vect;
     for(int i=0;i<n;i++){
          vector <int> vecttemp;
          int size;
          cin>>size;
         
         for(int j=0;j<size;j++){
            int num;
            cin>>num;
            vecttemp.push_back(num);
                 
             }
        vect.push_back(vecttemp);
             
         }
         for(int k=0;k<q;k++){
             int l,m;
             cin>>l>>m;
             cout<<vect[l][m]<<endl;
         }
    return 0;
}