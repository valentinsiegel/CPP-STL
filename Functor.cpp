#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

class Functor{

private:
    int offset;

public:

    //constructor with default offset = 20
    Functor(int _offset=20) : offset(_offset) {}

    void operator() (int i){
        cout<< "Using a class functor :"<<(i+offset)<<endl;
    }
};