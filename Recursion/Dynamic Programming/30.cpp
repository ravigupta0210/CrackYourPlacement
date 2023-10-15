// Guess Number Higher or Lower II



class Solution {
public:
int solve(int start,int end,vector<vector<int>> &dp){
    if(start >= end) return 0;
    if(dp[start][end]!=-1) return dp[start][end];
    int ans=INT_MAX;
    for(int i=start;i<=end;i++){
        ans=min(ans,i+max(solve(start,i-1,dp),solve(i+1,end,dp)));
    }
    return dp[start][end] = ans;
}
int solveTab(int n){
    vector<vector<int>> dp(n+2,vector<int>(n+2,0));
    for(int start = n;start>=1;start--){
        for(int end = start+1;end<=n;end++){
            int ans=INT_MAX;
            for(int i=start;i<=end;i++){
                ans=min(ans,i+max(dp[start][i-1],dp[i+1][end]));
            }
            dp[start][end] = ans;
        }
    }
    return dp[1][n];
}
    int getMoneyAmount(int n) {
        // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        // return solve(1,n,dp);
        return solveTab(n);
    }
};
