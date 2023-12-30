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
