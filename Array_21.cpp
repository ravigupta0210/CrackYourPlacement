// Majority Element


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //here the approach is simple 
        //sort and then return middle element
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
};
