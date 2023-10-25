// Subarray Sums Divisible by K


class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
       //hello here we solve that medium problem 
       //here we approach transfering modulus onwards and using map we count 
       int n=nums.size();
       int count=0,prefix_sum=0;
       unordered_map<int,int> mp;
       mp[0]=1;
       for(int i=0;i<n;i++){
           prefix_sum+=nums[i];
           int rem=prefix_sum%k;
           if(rem<0) rem+=k;
           count+=mp[rem];
           mp[rem]++;
       }
       return count;
    }
};
