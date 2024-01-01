// Rearrange Array Elements by Sign

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> negative,positive;
        for(auto i:nums){
            if(i<0) negative.push(i);
            else positive.push(i);
        }
        for(int i=0;i<n;i++){
            if(i%2 == 0){
                int temp = negative.top();
                negative.pop();
                ans[i] = temp;
            }
            else{
                int temp = positive.top();
                positive.pop();
                ans[i] = temp;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


// Minimize Maximum Pair Sum in Array

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int start = 0,end = n-1;
        int maxi = INT_MIN;
        while(start < end){
            int sum = nums[start]+nums[end];
            maxi = max(maxi,sum);
            start++;end--;
        }
        return maxi;
    }
};
