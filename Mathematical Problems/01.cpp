// Minimum Moves to Equal Array Elements



class Solution {
public:
    int minMoves(vector<int>& nums) {
        int m = INT_MAX;
        for(auto n:nums) m = min(m,n);
        int ans =0;
        for(auto n:nums) ans+=n-m;
        return ans;
    }
};
