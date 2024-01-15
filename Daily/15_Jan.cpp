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
