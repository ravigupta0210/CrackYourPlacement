// Two Sum


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++)
            if(nums[i]+nums[j] == target) return {i,j};
        }
        return {};
    }
};

// 4Sum

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        set<vector<int>> st;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                long long newTarget = (long long)target - (long long)nums[i]-(long long)nums[j];
                int k=j+1;
                int l=n-1;
                while(k<l){
                    long long sum = nums[k]+nums[l];
                    if(sum == newTarget)
                    {
                        st.insert({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        l--;
                    }
                    else if(sum < newTarget)
                    k++;
                    else l--;
                }
            }
        }
        for(auto i:st)
        ans.push_back(i);
        return ans;
    }
};


// Longest Consecutive Sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        int cnt = 1,maxi=0;
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]){
                if(nums[i]==nums[i-1]+1)
                cnt++;
                else{
                    maxi=max(maxi,cnt);
                    cnt=1;
                }
            }
        }
        return max(maxi,cnt);
    }
};


// Subarray with given XOR

int Solution::solve(vector<int> &A, int B) {
   int ans=0, count=0;
unordered_map<int,int>mp;
for(int i=0;i<A.size();i++){
ans^=A[i];
if(ans==B) count++;
if(mp.find(ans^B)!=mp.end()){
count+=mp[ans^B];
}
mp[ans]++;
}
return count;
}
