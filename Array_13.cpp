// 3Sum


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //here we solve this problem through two pointer approach
        int target=0;
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        set<vector<int>> temp;
        for(int i=0;i<nums.size();i++){
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==target){
                    temp.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }
                else if(sum<target) j++;
                else k--;
            }
        }
        for(auto i:temp)
        ans.push_back(i);
        return ans;
        //ok we forget to sort it first
    }
};
