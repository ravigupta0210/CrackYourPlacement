// Unique Binary Search Trees


class Solution {
public:
int solve(int n,vector<int> &dp){
    if(n<=1) return 1;
    if(dp[n]!=-1) return dp[n];
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=solve(i-1,dp)*solve(n-i,dp);
    }
    return dp[n] = ans;
}
int solveTab(int N){
    vector<int> dp(N+1,0);
    dp[0]=dp[1] = 1;
    for(int n=2;n<=N;n++){
         int ans=0;
    for(int i=1;i<=n;i++){
        ans+=dp[i-1]*dp[n-i];
    }
     dp[n] = ans;
    }
    return dp[N];
}
    int numTrees(int n) {
        // vector<int> dp(n+1,-1);
        // return solve(n,dp);
        return solveTab(n);
    }
};
