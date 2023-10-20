// Wildcard Matching


class Solution {
public:
bool solve(string &str,string &pat,int i,int j,vector<vector<int>> &dp){
    if(i==0 && j==0) return true;
    if(i>0 && j==0) return false;
    if(i==0 && j>0){
        for(int k=1;k<=j;k++){
            if(pat[k-1]!='*') return false;
        }
        return true;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    if(str[i-1] == pat[j-1] || pat[j-1]=='?')
    return dp[i][j] = solve(str,pat,i-1,j-1,dp);
    else if(pat[j-1]=='*')
    return dp[i][j] = (solve(str,pat,i-1,j,dp) || solve(str,pat,i,j-1,dp));
    else 
    return dp[i][j] = false;
}
bool solveTab(string &str,string &pat){
    vector<vector<int>> dp(str.length()+1,vector<int>(pat.length()+1,0));
    dp[0][0]=true;
    for(int j=1;j<=pat.length();j++){
        bool flag =true;
        for(int k=1;k<=j;k++){
            if(pat[k-1]!='*'){
                flag = false;
                break;
            }
        }
        dp[0][j] = flag;
    }
    for(int i=1;i<=str.length();i++){
        for(int j=1;j<=pat.length();j++){
            
            if(str[i-1] == pat[j-1] || pat[j-1]=='?')
             dp[i][j] = dp[i-1][j-1];
            else if(pat[j-1]=='*')
             dp[i][j] = (dp[i-1][j] || dp[i][j-1]);
            else 
             dp[i][j] = false;
        }
    }
    return dp[str.length()][pat.length()];
}
bool solveTab2(string &str,string &pat){
    // vector<vector<int>> dp(str.length()+1,vector<int>(pat.length()+1,0));
    vector<int> curr(pat.length()+1,0);
    vector<int> prev(pat.length()+1,0);
    prev[0]=true;
    for(int j=1;j<=pat.length();j++){
        bool flag =true;
        for(int k=1;k<=j;k++){
            if(pat[k-1]!='*'){
                flag = false;
                break;
            }
        }
        prev[j] = flag;
    }
    for(int i=1;i<=str.length();i++){
        for(int j=1;j<=pat.length();j++){
            
            if(str[i-1] == pat[j-1] || pat[j-1]=='?')
             curr[j] = prev[j-1];
            else if(pat[j-1]=='*')
             curr[j] = (prev[j] || curr[j-1]);
            else 
             curr[j] = false;
        }
        prev = curr;
    }
    return prev[pat.length()];
}
    bool isMatch(string s, string p) {
        // vector<vector<int>> dp(s.length()+1,vector<int>(p.length()+1,-1));
        // return solve(s,p,s.length(),p.length(),dp);
        return solveTab2(s,p);
    }
};
