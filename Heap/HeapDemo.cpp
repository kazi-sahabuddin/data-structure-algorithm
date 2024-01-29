#include <bits/stdc++.h>
#include "heap.h"
using namespace std;

int main(){

    Heap heap;
    int arr[] = {10, 15, 20, 13, 6, 90};

    for(int x: arr){
        heap.push(x);
    }
    while (!heap.empty())
    {
       cout<<heap.top()<<" ";
       heap.pop();
    }
    cout<<endl;
    


    return 0;
}