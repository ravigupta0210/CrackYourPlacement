// Minimum Elements


#include <bits/stdc++.h>
// int solve(vector<int> &num, int x,vector<int> &dp) {
//     if(x==0) return 0;
//     if(x<0) return INT_MAX;
//     if(dp[x]!=-1) return dp[x];
//     int mini=INT_MAX;
//     for(int i=0;i<num.size();i++){
//         int ans = solve(num,x-num[i],dp);
//         if(ans!=INT_MAX)
//         mini = min(mini,1+ans);
//     }
//     return dp[x] = mini;
// }
int solve(vector<int> &num, int x) {
    vector<int> dp(x+1,INT_MAX);
    dp[0] = 0;
    
    
    for(int i=1;i<=x;i++){
    for(int j=0;j<num.size();j++){
        if(i-num[j]>=0 && dp[i-num[j]] != INT_MAX)
        dp[i]=min(dp[i],1+dp[i-num[j]]);
    }
    }
    if(dp[x]!= INT_MAX) return dp[x];
    return -1;
    }
int minimumElements(vector<int> &num, int x)
{
    // vector<int> dp(x+1,-1);
    int ans = solve(num,x);
    // if(ans == INT_MAX) return -1;
    return ans;
}





