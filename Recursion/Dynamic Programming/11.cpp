// Combination Sum IV


#include <bits/stdc++.h> 
int solve(vector<int> &num, int tar,vector<int> &dp){
    if(tar == 0) return 1;
    if(tar < 0) return 0;
    if(dp[tar]!=-1) return dp[tar];
    int ans= 0;
    for(int i=0;i<num.size();i++){
        ans += solve(num,tar-num[i],dp);
    }
    return dp[tar] = ans;
}

int solveTab(vector<int> &num,int tar){
    vector<int> dp(tar+1,0);
    dp[0] = 1;
    
    for(int i=1;i<=tar;i++){
        int ans = 0;
        for(int j=0;j<num.size();j++){
            if(i-num[j] >= 0)
            ans += dp[i-num[j]];
        }
        dp[i] =  ans;
    }
    
    return dp[tar];
}

int findWays(vector<int> &num, int tar)
{
    // vector<int> dp(tar+1,-1);
    // return solve(num,tar,dp);
    return solveTab(num,tar);
}
