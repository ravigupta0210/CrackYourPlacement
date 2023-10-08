// Partition Equal Subset Sum



//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
bool solve(int n,int arr[],int target,int index,vector<vector<int>> &dp){
    if(index >= n) return 0;
    if(target==0) return 1;
    if(target<0) return 0;
    if(dp[index][target]!=-1) return dp[index][target];
    int include = solve(n,arr,target-arr[index],index+1,dp);
    int exclude = solve(n,arr,target,index+1,dp);
    
    return dp[index][target] = include or exclude;
}

bool solveTab(int n,int arr[],int t){
    
    vector<vector<int>> dp(n+1,vector<int>(t+1,0));
    for(int i=0;i<=n;i++)
    dp[i][0] = 1;
    
    for(int index = n-1;index >= 0;index--){
        for(int target = 0;target<=t;target++){
            int include = 0;
            if(target-arr[index] >= 0)
            include = dp[index+1][target-arr[index]];
            int exclude = dp[index+1][target];
            
            dp[index][target] = include or exclude;
        }
    }
    
    return dp[0][t];
    
}

bool solveTab2(int n,int arr[],int t){
    
    
    vector<int> curr(t+1,0);
    vector<int> next(t+1,0);
    
    curr[0]=1;
    next[0]=1;
    
    for(int index = n-1;index >= 0;index--){
        for(int target = 0;target<=t;target++){
            int include = 0;
            if(target-arr[index] >= 0)
            include = next[target-arr[index]];
            int exclude = next[target];
            
            curr[target] = include or exclude;
        }
        next = curr;
    }
    
    return next[t];
    
}
    int equalPartition(int N, int arr[])
    {
        int total = 0;
        for(int i=0;i<N;i++) 
        total+=arr[i];
        if(total & 1) return 0;
        // vector<vector<int>> dp(N+1,vector<int>(total/2+1,-1));
        return solveTab2(N,arr,total/2);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends
