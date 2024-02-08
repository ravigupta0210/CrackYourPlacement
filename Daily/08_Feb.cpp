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


// Balanced Binary Tree


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
int solve(TreeNode* root){
    if(root==NULL) return 0;
    int left=solve(root->left);
    int right=solve(root->right);
    return max(left,right)+1;
}
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        bool left=isBalanced(root->left);
        bool right=isBalanced(root->right);
        bool diff =abs(solve(root->left)-solve(root->right)) <= 1;
        return left && right && diff;
    }
};
