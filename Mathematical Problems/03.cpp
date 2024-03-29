// Maximum Product of Three Numbers


class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int prod1,prod2;
        prod1=nums[nums.size()-1] * nums[nums.size()-2] * nums[nums.size()-3];
        prod2 = nums[nums.size()-1] * nums[0] * nums[1];
        return max(prod1,prod2);
    }
};
