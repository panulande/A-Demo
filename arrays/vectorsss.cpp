#include<iostream>
using namespace std;
#include<vector>

void display(vector <int> &v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector <int> vect1; //zero length vector
    vector <char> vect2(5); // char vector with length 5
    int element,size;  //
    
    cout<<"enter the size of vector"<<endl;
    cin>>size;

    for(int i=0;i<size;i++){
        cout<<"enter an element to add this vector.";
        cin>>element;
        vect1.push_back(element); 
        


    }
    vect1.pop_back();
    display(vect1);
    vector<int> ::iterator iter=vect1.begin(); //scope resolution operator makes iter to point at the beginning index of the vector
    vect1.insert(iter,5, 566);
    display(vect1);
    vector <int> vec4(6,13);
    return 0;

}