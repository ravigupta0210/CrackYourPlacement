//  Pizza With 3n Slices


class Solution {
public:
int solve(vector<int>& slices,int s,int e,int n,vector<vector<int>> &dp){
    if(n==0 || s>e) return 0;
    if(dp[s][n] != -1) return dp[s][n];
    int include = slices[s] + solve(slices,s+2,e,n-1,dp);
    int exclude = 0 + solve(slices,s+1,e,n,dp);
    return dp[s][n] = max(include,exclude);
}
int solveTab(vector<int>& slices,int k){

   
    vector<int> prev1(k+2,0);
    vector<int> curr1(k+2,0);
    vector<int> next1(k+2,0);
    for(int s = k-2;s>=0;s--){
        for(int n=1;n<=k/3;n++){
            int include = slices[s] + next1[n-1];
            int exclude = 0 + curr1[n];
            prev1[n] = max(include,exclude);
        }
        next1 = curr1;
        curr1=prev1;
    }
    int case1  =prev1[k/3];
    
    vector<int> prev2(k+2,0);
    vector<int> curr2(k+2,0);
    vector<int> next2(k+2,0);
    for(int s = k-1;s>=1;s--){
        for(int n=1;n<=k/3;n++){
            int include = slices[s] + next2[n-1];
            int exclude = 0 + curr2[n];
            prev2[n] = max(include,exclude);
        }
        next2 = curr2;
        curr2=prev2;
    }
    int case2  =prev2[k/3];
    return max(case1,case2);
}
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        // vector<vector<int>> dp1(n+1,vector<int>(n/3+1,-1));
        // vector<vector<int>> dp2(n+1,vector<int>(n/3+1,-1));
        // int case1  = solve(slices,0,n-2,n/3,dp1);
        // int case2  = solve(slices,1,n-1,n/3,dp2);
        // return max(case1,case2);
        return solveTab(slices,n);
    }
};
