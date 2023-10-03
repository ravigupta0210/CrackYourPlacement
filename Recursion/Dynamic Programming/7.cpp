// Painting Fences



#include <bits/stdc++.h> 
#define MOD 1000000007
long long int solve(int n,vector<long long int> &dp){
    if(n==1)
    return 2;
    if(n==2)
    return 2*2;
    if(dp[n]!=-1) return dp[n];
    long long int same = (solve(n-2,dp)*1)%MOD;
    long long int different =(solve(n-1,dp)*1)%MOD;
    return dp[n]=(same+different)%MOD;
}
int countWays(int n)
{
    vector<long long int> dp(n+1,-1);
   return solve(n,dp);
}
