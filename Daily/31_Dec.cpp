// Maximum Number of Coins You Can Get

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int ans = 0;
        int n = piles.size()/3;
        sort(piles.begin(),piles.end());
        for(int i = piles.size()-1;i>=0;i--){
            if(n > 0){
                ans+=piles[i-1];
                n--;
                i--;
            }
        }
        return ans;
    }
};
