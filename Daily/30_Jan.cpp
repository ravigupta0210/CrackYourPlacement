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


// Kth Largest Element in an Array


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxheap;
        for(auto i:nums){
            if(maxheap.size()<(nums.size()-k+1)){
                maxheap.push(i);
            }
            else{
                if(maxheap.top()>i){
                    maxheap.pop();
                    maxheap.push(i);
                }
            }
        }
        return maxheap.top();
    }
};
