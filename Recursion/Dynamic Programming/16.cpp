// Reducing Dishes


class Solution {
public:
int solve(vector<int>& sat,int n,int index,int time,vector<vector<int>> &dp){
    if(index == n) return 0;
    if(dp[index][time]!=-1) return dp[index][time];

    int include = sat[index]*(time+1)+solve(sat,n,index+1,time+1,dp);
    int exclude = 0+ solve(sat,n,index+1,time,dp);
    return dp[index][time] = max(include,exclude);
}
int solveTab(vector<int>& sat,int n){

    vector<vector<int>> dp(n+1,vector<int>(n+1,0));

    for(int index = n-1;index>=0;index--){
        for(int time = index; time >= 0;time--){

            int include = sat[index]*(time+1)+dp[index+1][time+1];
            int exclude = 0+ dp[index+1][time];
            dp[index][time] = max(include,exclude);

        }
    }
return dp[0][0];
    
}

int solveSO(vector<int>& sat,int n){

    vector<int> curr(n+1,0);
    vector<int> next(n+1,0);

    for(int index = n-1;index>=0;index--){
        for(int time = index; time >= 0;time--){

            int include = sat[index]*(time+1)+next[time+1];
            int exclude = 0+ next[time];
            curr[time] = max(include,exclude);

        }
        next  = curr;
    }
return next[0];
    
}

    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        // return solve(satisfaction,n,0,0,dp);
        return solveSO(satisfaction,n);
    }
};
