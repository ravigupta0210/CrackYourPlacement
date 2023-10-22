// Move Zeroes



class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //this is one of the easy question here we approached through index pointer
        int start=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                swap(nums[i],nums[start]);
                start++;
            }
        }
    }
};
