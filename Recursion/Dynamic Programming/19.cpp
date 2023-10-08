// Maximum Height by Stacking Cuboids 


class Solution {
public:
bool isSafe(vector<int> base,vector<int> newBase){
    if(newBase[0] <= base[0] &&
       newBase[1] <= base[1] && 
       newBase[2] <= base[2]) return true;
       else return false;
}
// int solve(vector<vector<int>>& cuboids,int n,int curr,int prev,vector<vector<int>> &dp){
//     if(curr < 0) return 0;
//     if(dp[curr][prev+1]!=-1) return dp[curr][prev+1];
//     int include = 0;
//     if(prev==-1 || isSafe(cuboids,curr,prev))
//     include = cuboids[curr][2]+solve(cuboids,n,curr-1,curr,dp);
//     int exclude = 0+solve(cuboids,n,curr-1,prev,dp);
//     return dp[curr][prev+1] = max(include,exclude);
// }

int solveTab(vector<vector<int>>& cuboids,int n){
    vector<int> currRow(n+1,0);
    vector<int> prevRow(n+1,0);

    for(int curr = n-1;curr>=0;curr--){
        for(int prev = curr-1;prev>=-1;prev--){
            int include = 0;
            if(prev == -1 || isSafe(cuboids[curr],cuboids[prev]))
            include = cuboids[curr][2]+prevRow[curr+1];
            int exclude = 0+prevRow[prev+1];
            currRow[prev+1]  = max(include,exclude);
        }
        prevRow  = currRow;
    }
    return prevRow[0];
}

    int maxHeight(vector<vector<int>>& cuboids) {
       for(auto &a:cuboids)
       sort(a.begin(),a.end());
       sort(cuboids.begin(),cuboids.end());
       int n  =cuboids.size();
    //    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));


    //    return solve(cuboids,cuboids.size(),cuboids.size()-1,-1,dp); 
    return solveTab(cuboids,n);
    }
};
