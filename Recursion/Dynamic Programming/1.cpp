// Fibonacci Number


class Solution {
public:
// int solve(int n,vector<int> &dp){
//     if(n==0 || n==1){
//         return n;
//     }
//     if(dp[n]!=-1) return dp[n];
//     int ans =  solve(n-1,dp)+solve(n-2,dp);
//     return dp[n] = ans;
// }
int solveTab(int n){
    if(n<2) return n;
    vector<int> dp(n+1,0);
    dp[0] = 0;
    dp[1] = 1;

    for(int i=2;i<=n;i++){
        dp[i]= dp[i-1]+dp[i-2];
        
    }
    return dp[n];
}
    int fib(int n) {
        // vector<int> dp(n+1,-1);
        // return solveTab(n);
        if(n<2) return n;
        int prev1 = 1,prev2=0,curr;
        for(int i=2;i<=n;i++){
            curr = prev1+prev2;
            prev2=prev1;
            prev1=curr;
        }
        return curr;
    }
};
