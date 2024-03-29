// Diameter of Binary Tree



class Solution {
public:
int solve(TreeNode* root,int &d){
    if(root == NULL) return 0;
    int left=solve(root->left,d);
    int right=solve(root->right,d);
    d=max(d,left+right+1);
    return max(left,right)+1;
}
    int diameterOfBinaryTree(TreeNode* root) {
        int d=0;
        solve(root,d);
        return d-1;
    }
};
