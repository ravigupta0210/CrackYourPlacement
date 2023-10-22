// Best Time to Buy and Sell Stock


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // so this question is generally a real world problem 
        //brute force simple
        int mini=INT_MAX,profitToday=0,overallProfit=0;
        for(int i=0;i<prices.size();i++){
            if(mini>prices[i])
            mini=prices[i];
            profitToday=prices[i]-mini;
            if(overallProfit<profitToday) overallProfit = profitToday;
        }
        //we have to return an integer value
        return overallProfit;
    }
};
