// Count derangements


#include<bits/stdc++.h>
#define MOD 1000000007
long long int solve(int n,vector<long long int> &dp){
    if(n==1) return 0;
    if(n==2) return 1;
    if(dp[n]!=-1) return dp[n];
    return dp[n] = ((n-1) * (solve(n-1,dp)%MOD+solve(n-2,dp)%MOD))%MOD;
}
long long int solveTab(int n){

    vector<long long int> dp(n+1,0);
    
    dp[1]=0,dp[2]=1;
    
    for(int i=3;i<=n;i++){
        dp[i] = ((i-1) * (dp[i-1]%MOD+dp[i-2]%MOD))%MOD;
    }
    return dp[n];
}
long long int solveSO(int n){

    long long int prev2=0,prev1=1;
    
    for(int i=3;i<=n;i++){
        int ans = ((i-1) * (prev1%MOD+prev2%MOD))%MOD;
        prev2=prev1;
        prev1=ans;
    }
    return prev1;
}
long long int countDerangements(int n) {
    // vector<long long int> dp(n+1,-1);
    // return solve(n,dp);
    return solveSO(n);
}
