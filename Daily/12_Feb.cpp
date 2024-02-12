// Flatten Binary Tree to Linked List


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
TreeNode* solve(TreeNode* root){
    root=root->left;
    while(root->right)
    root=root->right;
    return root;
}
    void flatten(TreeNode* root) {
        TreeNode* curr=root;
        while(curr){
            if(curr->left){
                TreeNode* pred = solve(curr);
                pred->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
            }
            curr=curr->right;
        }
    }
};
