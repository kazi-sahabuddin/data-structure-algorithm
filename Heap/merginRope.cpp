#include <bits/stdc++.h>
using namespace std;

int mergeRope(vector<int>&nums){
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int num:nums){
        pq.push(num);
    }
    int ans = 0;
    while(pq.size() > 1){
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        ans+=a+b;
        pq.push(a+b);
    }

    return ans;

}

int main() {

    vector<int> nums;
    int n;
    cin>>n;
    while (n--)
    {
        int a;
        cin>>a;
        nums.push_back(a);
    }
    cout<<mergeRope(nums)<<endl;
    
    
    return 0;
}