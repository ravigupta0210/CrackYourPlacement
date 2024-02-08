// Binary Tree Level Order Traversal


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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(root==NULL) return ans;

        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int> temp;
            for(int i=0;i<size;i++){
                TreeNode* frontNode=q.front();
                q.pop();
                if(frontNode->left) q.push(frontNode->left);
                if(frontNode->right) q.push(frontNode->right);
                temp.push_back(frontNode->val);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};


// Maximum Depth of Binary Tree


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
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> q;
       
        if(root==NULL) return 0;
        int ans=0;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            
            for(int i=0;i<size;i++){
                TreeNode* frontNode=q.front();
                q.pop();
                if(frontNode->left) q.push(frontNode->left);
                if(frontNode->right) q.push(frontNode->right);
                
            }
            ans++;
        }
        return ans;
    }
};


// Diameter of Binary Tree


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
int solve(TreeNode* root,int &ans){
    if(root==NULL) return 0;
    int left=solve(root->left,ans);
    int right=solve(root->right,ans);
    ans=max(ans,left+right);
    return 1+max(left,right);
}
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        solve(root,ans);
        return ans;
    }
};
