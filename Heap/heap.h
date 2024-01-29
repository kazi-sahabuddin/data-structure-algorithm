#include <vector>
using namespace std;

class Heap{
    vector<int> v;
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

};