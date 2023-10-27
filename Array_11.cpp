// Find All Duplicates in an Array


class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
       //here the approach is simple
       //first sort then push elements in vector
       vector<int> ans;
       sort(nums.begin(),nums.end());
       for(int i=0;i<nums.size()-1;i++){
           if(nums[i]==nums[i+1]) ans.push_back(nums[i]);

       }
       return ans;
    }
};
