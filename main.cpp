#include <iostream>
#include <array>
#include <algorithm>
#include <cstring>
#include "Functor.cpp"

using namespace std;

//fonction pour afficher
void print(int i) {
    cout << "Pointer on function :" << i << endl;
}

int main() {

    array<int, 3> tabs{10, 50, 16};
    array<int, 3> tabs2{11, 52, 16};

    //use of fill fonction
    tabs.fill(8);

    //swaps tabs2 in tabs
    tabs.swap(tabs2);

    //simple loop
    if (!tabs.empty()) {
        for (unsigned int i = 0; i < tabs.size(); i++) {
            std::cout << "Normal loop :" << tabs[i] << endl;
    }
    }

    //use of max_size()
    std::cout<<tabs.at(tabs.max_size()-1)<<endl;

    //auto + new loops
    for (auto val : tabs) {
        cout << "For each loop :"<<val << endl;
    }

    //loop using an iterator
    for (auto it = tabs.begin(); it != tabs.end(); it++) {
        cout << "Iterator :" << *it << endl;
    }

    //using pointer on fonction
    for_each(tabs.begin(), tabs.end(), print);

    //instantiate functor with 30 offset
    Functor functor(30);

    //use a pointer of the instance of functor we created
    for_each(tabs.begin(), tabs.end(), Functor(functor));

    int a = 15;
    int b = 20;

    //copies a
    for_each(tabs.begin(), tabs.end(), [a] (int i) { cout << "Lambda :" << (i < a) << endl; });

    //modifies a
    for_each(tabs.begin(), tabs.end(), [&a] (int i) { cout << "Lambda :" << (a = a + i) << endl; });

    cout<<"A after lamba :"<<a<<endl;

    //not sure how he knows v
    cout << [b] (int v) ->bool { return (v<b); } (a) <<endl;

    cout << "Before memcpy :" << tabs[0] << ";" << tabs[1] << ";" << tabs[2] << endl;

    int tab0 [] = { 10,  20, 15};

    //same as swap()
    memcpy(tabs.data(), tab0, tabs.size()*sizeof(int));

    cout << "After memcpy :" << tabs[0] << ";" << tabs[1] << ";" << tabs[2] << endl;

    sort(tabs.begin(), tabs.end());

    cout << "Sorted :" << tabs[0] << ";" << tabs[1] << ";" << tabs[2] << endl;

    //return the iterator so we have to access its value with *
    cout << "Max of tabs " << *(min_element(tabs.begin(), tabs.end())) << endl;

    cout << "Number of 20 in tabs : " << count(tabs.begin(), tabs.end(), 20) << endl;

    int c = 10;

    //count_if + comparison
    cout << "Number of numbers sup to 15 in tabs : " << count_if(tabs.begin(), tabs.end(), [c](int a ) { return a>c;})<<endl;

    /*
     * VECTORS
     */

    vector<int> vector {3, 5, 6};

    //addds at the end
    vector.push_back(5);

    cout<< "Vector size :" << vector.size() << "; Vector capacity :" << vector.capacity() << "; Vector max size :" << vector.max_size() <<endl;

    vector.resize(10);

    return 0;
}  

