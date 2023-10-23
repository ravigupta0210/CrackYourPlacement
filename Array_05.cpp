// Find the Duplicate Number


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //here we go through simple approach 
        //first sort and using loop to find that number
        sort(nums.begin(),nums.end());
        int ans;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                ans=nums[i];
                break;
            }
        }
        return ans;
    }
};
