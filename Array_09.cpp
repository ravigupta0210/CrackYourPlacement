// Best Time to Buy and Sell Stock II


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //here we have amazing solution of that problem 
        //simple
        int profit=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>prices[i-1])
            profit+=prices[i]-prices[i-1];
        }
        return profit;
    }
};
