// Best Time to Buy and Sell Stock II



class Solution {
public:
int solve(int index,int buy,vector<int>& prices,vector<vector<int>> &dp){
if(index == prices.size()) return 0;
if(dp[index][buy] != -1) return dp[index][buy];
int profit = 0;
if(buy){
int buyKaro = -prices[index]+solve(index+1,0,prices,dp);
int skipKaro = 0+solve(index+1,1,prices,dp);
profit = max(buyKaro,skipKaro);
}
else{
int sellKaro = prices[index]+solve(index+1,1,prices,dp);
int skipKaro = 0+solve(index+1,0,prices,dp);
profit = max(sellKaro,skipKaro);
}
return dp[index][buy] = profit;
}

int solveTab(vector<int>& prices){
    int n = prices.size();
    vector<vector<int>> dp(prices.size()+1,vector<int>(2,0));
    for(int index = n-1;index>=0;index--){
        for(int buy=0;buy<=1;buy++){
            int profit = 0;
            if(buy){
            int buyKaro = -prices[index]+dp[index+1][0];
            int skipKaro = 0+dp[index+1][1];
            profit = max(buyKaro,skipKaro);
            }
            else{
            int sellKaro = prices[index]+dp[index+1][1];
            int skipKaro = 0+dp[index+1][0];
            profit = max(sellKaro,skipKaro);
            }
            dp[index][buy] = profit;
        }
    }
    return dp[0][1];
}

int solveTab2(vector<int>& prices){
    int n = prices.size();
    vector<int> curr(2,0);
    vector<int> next(2,0);
    for(int index = n-1;index>=0;index--){
        for(int buy=0;buy<=1;buy++){
            int profit = 0;
            if(buy){
            int buyKaro = -prices[index]+next[0];
            int skipKaro = 0+next[1];
            profit = max(buyKaro,skipKaro);
            }
            else{
            int sellKaro = prices[index]+next[1];
            int skipKaro = 0+next[0];
            profit = max(sellKaro,skipKaro);
            }
            curr[buy] = profit;
        }
        next = curr;
    }
    return next[1];
}

    int maxProfit(vector<int>& prices) {
        // vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        // return solve(0,1,prices,dp);
        return solveTab2(prices);
    }
};
