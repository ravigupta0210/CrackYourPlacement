// Minimum Number of Operations to Move All Balls to Each Box

class Solution {
public:
    vector<int> minOperations(string boxes) {
       vector<int> res;
       int ans;
       for(int i=0;i<boxes.length();i++){
           ans=0;
           for(int j=0;j<boxes.length();j++){
               if(boxes[j]=='1')
               ans += abs(i-j);
           }
           res.push_back(ans);
       } 
       return res;
    }
};



// Maximum Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
TreeNode* solve(vector<int> &nums,int start,int end){
    if(start > end) return NULL;
    int p =start;
    for(int i=p+1;i<=end;i++){
        if(nums[i]>nums[p])
        p=i;
    }
    TreeNode* root = new TreeNode(nums[p]);
    root->left = solve(nums,start,p-1);
    root->right = solve(nums,p+1,end);
    return root;
}
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return solve(nums,0,nums.size()-1);
    }
};


// Difference Between Ones and Zeros in Row and Column

class Solution {
public:
int solve1(vector<vector<int>>& grid,int index,int n){
    int ans = 0;
    for(int i=0;i<n;i++){
        if(grid[index][i] == 1)
        ans++;
    }
    return ans;
}
int solve2(vector<vector<int>>& grid,int index,int n){
    int ans = 0;
    for(int i=0;i<n;i++){
        if(grid[i][index] == 1)
        ans++;
    }
    return ans;
}
int solve3(vector<vector<int>>& grid,int index,int n){
    int ans = 0;
    for(int i=0;i<n;i++){
        if(grid[index][i] == 0)
        ans++;
    }
    return ans;
}
int solve4(vector<vector<int>>& grid,int index,int n){
    int ans = 0;
    for(int i=0;i<n;i++){
        if(grid[i][index] == 0)
        ans++;
    }
    return ans;
}
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // vector<vector<int>> ans( m , vector<int> (n, 0));
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         int oneRow = solve1(grid,i,n);
        //         int oneCol = solve2(grid,j,m);
        //         int zeroRow = solve3(grid,i,n);
        //         int zeroCol = solve4(grid,j,m);
        //         int temp = oneRow+oneCol - zeroRow - zeroCol;
        //         ans[i][j] = temp;
        //     }
        // }
        // return ans;
        vector<int> row(m);
        vector<int> col(n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                row[i] += grid[i][j];
                col[j] += grid[i][j];
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                grid[i][j] = 2*(row[i]+col[j]) - m- n;
            }
        }
        return grid;
    }
};
