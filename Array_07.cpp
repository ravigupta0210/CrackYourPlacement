// Remove Duplicates from Sorted Array


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    //here we simple using two pointer approach
    int i=0;
    for(int j=1;j<nums.size();j++){
        if(nums[i]!=nums[j])
        i++;
        nums[i]=nums[j];
    }
    //because index start from 0
    return i+1;
    }
};
