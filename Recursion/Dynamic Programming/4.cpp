// Maximum sum of non-adjacent elements


#include <bits/stdc++.h> 
int solve(vector<int> &nums,int n,vector<int> &dp){
    if(n<0) return 0;
    if(n==0) return nums[0];
    if(dp[n]!=-1)
    return dp[n];
    int ans=max(solve(nums,n-2,dp)+nums[n],solve(nums,n-1,dp));
    return dp[n]=ans;
}
int solve2(vector<int> &nums,int n){
    vector<int> dp(n,0);
    dp[0]=nums[0];
    for(int i=1;i<=n;i++){
        dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
    }
    return dp[n-1];
    
}
int solve3(vector<int> &nums,int n){
    int prev2=0,prev1=nums[0];

   
    for(int i=1;i<n;i++){
        int ans=max(prev2+nums[i],prev1);
        prev2=prev1;
        prev1=ans;
    }
    return prev1;
    
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    // vector<int> dp(n+1,-1);
    // return solve(nums,n-1,dp);
    // return solve2(nums,n);
    return solve3(nums,n);

}
