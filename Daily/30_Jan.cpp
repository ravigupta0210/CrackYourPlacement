// Min Heap

#include <bits/stdc++.h> 
vector<int> minHeap(int n, vector<vector<int>>& q) {
    vector<int> ans;
    priority_queue<int,vector<int>,greater<int>> minheap;
    for(auto i:q){
        if(i[0]==0)
        minheap.push(i[1]);
        else{
            ans.push_back(minheap.top());
            minheap.pop();
        }
    }
    return ans;
}
