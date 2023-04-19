#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

int main(){
    vector <int> hello {1,2,3,4,5};
    cout<<*hello.begin()<<endl;    //returns an iterator pointing to the first element of the vector
    cout<<*(hello.end()-1)<<endl;  //returns an itertor pointing to a therotical element of the vector
    *hello.begin()=9;
    cout<<hello[0]<<endl;
    //cout does the same funnction that is points the iterator to the first and theorotical last values but while dereferencing it returns a constant value
    //rend and rbegin does the reverse functions
    //there are also crbegin and crend fuctions which combine the functions
    hello.push_back(32);
    cout<<*(hello.end()-1)<<endl;
    cout<<hello.size()<<endl; //end of elements
    cout<<hello.max_size()<<endl; //max size which can be allocatefd
    cout<<hello.capacity()<<endl; //return the current capacity which can be allocated
    hello.resize(2);
    cout<<hello.size()<<endl;

    return 0;
}