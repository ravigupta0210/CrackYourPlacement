// Minimum Sideway Jumps


class Solution {
public:
int solve(vector<int> &obs,int currLane,int currPos,vector<vector<int>> &dp){
    int n = obs.size()-1;
    if(currPos == n) return 0;
    if(dp[currLane][currPos]!=-1) return dp[currLane][currPos];
    if(obs[currPos+1]!=currLane)
    return dp[currLane][currPos] = solve(obs,currLane,currPos+1,dp);
    else{
        int ans = INT_MAX;
        for(int i=1;i<=3;i++){
            if(currLane!=i && obs[currPos]!=i)
            ans=min(ans,1+solve(obs,i,currPos,dp));
        }
        return dp[currLane][currPos] = ans;
    }
}
    int minSideJumps(vector<int>& obstacles) {
        vector<vector<int>> dp(4,vector<int>(obstacles.size()+1,-1));
        return solve(obstacles,2,0,dp);
    }
};
