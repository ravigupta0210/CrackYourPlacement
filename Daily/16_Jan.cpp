// Rotate Image

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //transpose
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++)
            swap(matrix[i][j],matrix[j][i]);
        }
        for(int i=0;i<n;i++)
        reverse(matrix[i].begin(),matrix[i].end());
    }
};


// Merge Intervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        ans.push_back(intervals[0]);
        int j=0;
        for(int i=1;i<intervals.size();i++){
            if(ans[j][1] >= intervals[i][0]){
                ans[j][1] = max(ans[j][1],intervals[i][1]);
            }
            else{
                ans.push_back(intervals[i]);
                j++;
            }
        }
        return ans;
    }
};


// Merge Sorted Array

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0) return ;
        int j=0;
        nums1.resize(m+n);
        for(int i=m+n-1;i>=m;i--){
            if(nums1[i]==0){
                nums1[i] = nums2[j];
                j++;
            }
        }
        sort(nums1.begin(),nums1.end());
    }
};


// Find the Duplicate Number

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto num:nums)
        mp[num]++;
        int ans;
        for(auto map:mp){
            if(map.second >= 2)
            ans=map.first;
        }
        return ans;
    }
};
