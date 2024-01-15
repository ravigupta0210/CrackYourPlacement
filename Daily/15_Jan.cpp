// Set Matrix Zeroes


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==0){
                    for(int k=0;k<row;k++)
                    if(matrix[k][j]!=0) matrix[k][j]=1e9;
                    for(int k=0;k<col;k++)
                    if(matrix[i][k]!=0) matrix[i][k]=1e9;
                }
            }
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==1e9)
                matrix[i][j]=0;
            }
        }

    }
};

// Pascal's Triangle

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        ans[0] = {1};
        for(int i=1;i<numRows;i++){
            ans[i].resize(i+1);
            ans[i][0] = 1;
            for(int j=1;j<i;j++)
            ans[i][j] = ans[i-1][j]+ans[i-1][j-1];
            ans[i][i] =1;
        }
        return ans;
    }
};


// Next Permutation

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size()-1;int temp;
        for(int i=n;i>0;i--){
            if(nums[i]>nums[i-1]){
                temp=i;
                break;
            }
        }
        if(temp==0)
        sort(nums.begin(),nums.end());
        else{
            int swapElement = nums[temp-1];
            for(int i=temp;i<=n;i++){
                if(nums[i]-swapElement > 0)
                swap(nums[i],nums[temp-1]);
            }
            sort(nums.begin()+temp,nums.end());
        }
    }
};


// Maximum Subarray


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = INT_MIN;int temp=0;
        for(int i=0;i<nums.size();i++){
            temp+=nums[i];
            sum=max(sum,temp);
            if(temp<0) temp=0;
        }
        return sum;
    }
};
