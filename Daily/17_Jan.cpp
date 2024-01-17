// Search a 2D Matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int start = 0;
        int end = row*col-1;
        

        while(start <= end){
            int middle=start+(end-start)/2 ;
            int element = matrix[middle/col][middle%col];
            if(target == element) return 1;
            else if(target < element)
            end = middle-1;
            else start = middle+1;
        }
        return 0;
    }
};


// Pow(x, n)

class Solution {
public:
    double myPow(double x, int n) {
        return pow(x,n);
    }
};

//  Majority Element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto ele:nums)
        mp[ele]++;
        
        int ans;
        int freq=0;
        for(auto map:mp){
            if(map.second > freq)
            {ans = map.first;
            freq = map.second;}
        }
        return ans;
    }
};


// Majority Element II

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> mp;
        for(auto i:nums)
        mp[i]++;
        for(auto map:mp){
            if(map.second > nums.size()/3)
            ans.push_back(map.first);
        }
        return ans;
    }
};


//  Unique Paths

class Solution {
public:
int solve(int i,int j,int m,int n,vector<vector<int>> &dp){
    if(i>=m || j>=n ) return 0;
    if(i==m-1 && j==n-1) return 1;
    if(dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = solve(i+1,j,m,n,dp)+solve(i,j+1,m,n,dp);
}
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(0,0,m,n,dp);
    }
};
