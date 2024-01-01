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


// Number of Laser Beams in a Bank

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        if(bank.size()==1) return 0;
        vector<int> once;
        int count = 0;
        for(auto i:bank){
            count=0;
            for(auto j:i){
                if(j=='1') count++;
            }
            if(count) once.push_back(count);
        }
        if(once.size()<=1) return 0;
        int ans = 0;
        for(int i=0;i<once.size()-1;i++){
            ans+=once[i]*once[i+1];
        }
        return ans;
    }
};


// Finding the Users Active Minutes

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int,set<int>> mp;
        for(int i=0;i<logs.size();i++){
            mp[logs[i][0]].insert(logs[i][1]);
        }
        vector<int> ans(k,0);
        for(auto i:mp){
            int m = i.second.size()-1;
            ans[m]++;
        }
        return ans;
    }
};


// Find the Prefix Common Array of Two Arrays

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n);
        int index = 0;
        for(int i=0;i<n;i++){
            int count=0;
            set<int> set;
            for(int j=0;j<=i;j++){
                set.insert(A[j]);
            }
            for(int k=0;k<=i;k++){
                if(!set.insert(B[k]).second)
                count++;
            }
            ans[index++]=count;
        }
        return ans;
    }
};
