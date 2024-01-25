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
