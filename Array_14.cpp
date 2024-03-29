// 4Sum



class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //here we solve it also by two pointer approach
        vector<vector<int>> ans;
        set<vector<int>> st;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                long long newTarget = (long long)target - (long long)nums[i] - (long long)nums[j];
                int k=j+1;
                int l=n-1;
                while(k<l){
                    int sum=nums[k]+nums[l];
                    if(sum==newTarget){
                        st.insert({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        l--;
                    }
                    else if(sum<newTarget)
                    k++;
                    else l--;
                }
            }
        }
        for(auto i:st)
        ans.push_back(i);
        return ans;
        //so here we add long long to solve ranging problem
    }
    //ohh sorry we forgot to remove nums[i]ans nums[j]
};
