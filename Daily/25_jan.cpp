// Subset Sums


//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
void solve(vector<int> arr,int n,int i,vector<int> &ans,int sum){
    if(i>=n){
        ans.push_back(sum);
        return ;
    }
    solve(arr,n,i+1,ans,sum);
    solve(arr,n,i+1,ans,sum+arr[i]);
}
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        solve(arr,N,0,ans,0);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends


// Subsets II


class Solution {
public:
void solve(vector<int>& nums,int i,int n,set<vector<int>> &st,vector<int> &temp){
    if(i>=n){
        st.insert(temp);
        return ;
    }
    solve(nums,i+1,n,st,temp);
    temp.push_back(nums[i]);
    solve(nums,i+1,n,st,temp);
    temp.pop_back();
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> st;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        solve(nums,0,nums.size(),st,temp);
        for(auto i:st)
        ans.push_back(i);
        return ans;
    }
};


// Combination Sum

class Solution {
public:
void solve(vector<int>& candidates, int target,vector<int> temp,set<vector<int>> &st){
    if(target<0)
    return;
    if(target==0){
        sort(temp.begin(),temp.end());
        st.insert(temp);
        return ;
    }
    for(int i=0;i<candidates.size();i++){
        temp.push_back(candidates[i]);
        solve(candidates,target-candidates[i],temp,st);
        temp.pop_back();
    }
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        set<vector<int>> st;
        vector<int> temp;
        solve(candidates,target,temp,st);
        for(auto i:st)
        ans.push_back(i);
        return ans;
    }
};


// Combination Sum II

class Solution {
public:
void solve(vector<int>& arr, int target,vector<vector<int>> &ans,vector<int> temp,int index){
    if(target == 0){
        ans.push_back(temp);
        return ;
    }
    for(int i=index;i<arr.size();i++){
        if(arr[i]<=target){
            temp.push_back(arr[i]);
            solve(arr,target-arr[i],ans,temp,i+1);
            temp.pop_back();
        }
        else break;
        while(i< arr.size()-1 && arr[i]==arr[i+1]) i++;
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        solve(candidates,target,ans,temp,0);
        return ans;
    }
};
