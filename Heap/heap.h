#include <vector>
using namespace std;

class Heap{
    vector<int> v;
    void heapify(int i){
        int left = i*2;
        int right = i*2 + 1;
        int minIdx = i;

        if(left < v.size() && v[left] < v[i]){
            minIdx = left;
        }

        if(right < v.size() && v[right] < v[minIdx]){
            minIdx = right;
        }

        if(minIdx != i){
            swap(v[i], v[minIdx]);
            heapify(minIdx);
        }
    }
public:
    Heap(int defaultSize = 10){
        v.reserve(defaultSize);
        v.push_back(-1);
    }

    void push(int data){
        //add data to end of the heap
        v.push_back(data);
        int idx = v.size()-1;
        int parentIdx = idx/2;

        while (idx > 1 && v[idx] < v[parentIdx])
        {
            swap(v[idx], v[parentIdx]);
            idx = parentIdx;
            parentIdx /= 2;
        }        
    }
    //Get min value of heap
    int top(){
        return v[1];
    }

    void pop(){
        int idx = v.size()-1;
        swap(v[1],v[idx]);
        v.pop_back();
        heapify(1);
    }

    bool empty(){
        return v.size() == 1;
    }

};