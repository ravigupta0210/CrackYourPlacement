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


// Maximum Sum Combinations


vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    priority_queue<int,vector<int>,greater<int>> minheap;
    sort(A.begin(),A.end(),greater<int>());
    sort(B.begin(),B.end(),greater<int>());
    vector<int> ans(C);
    
    for(int i=0;i<C;i++){
        minheap.push(A[i]+B[i]);
    }
    
    for(int i=0;i<A.size();i++){
        for(int j=0;j<B.size();j++){
            if(i==j) continue;
            if(A[i]+B[j] > minheap.top()){
                minheap.pop();
                minheap.push(A[i]+B[j]);
            }
            else break;
        }
    }
    for(int i=C-1;i>=0;i--){
        ans[i]=minheap.top();
        minheap.pop();
    }
    return ans;
}


// Find Median from Data Stream


class MedianFinder {
public:
int n;
double median;
priority_queue<int> left;
priority_queue<int,vector<int>,greater<int>> right;
    MedianFinder() {
        n=0;
    }
    
    void addNum(int num) {
        if(!left.empty() && left.top()>num){
            left.push(num);
            if(left.size() > right.size()+1){
                right.push(left.top());
                left.pop();
            }
        }
        else{
            right.push(num);
            if(right.size()>left.size()+1){
                left.push(right.top());
                right.pop();
            }
        }
        n++;
    }
    
    double findMedian() {
        if(n&1) {median=left.size()>right.size()?left.top():right.top();}
        else{
            median=(left.top()+right.top())/2.0;
        }
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
