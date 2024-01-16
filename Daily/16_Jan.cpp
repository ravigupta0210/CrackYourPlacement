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
