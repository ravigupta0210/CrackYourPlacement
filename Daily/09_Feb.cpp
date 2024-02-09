// Binary Tree Maximum Path Sum


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
    int left=max(0,solve(root->left,ans));
    int right=max(0,solve(root->right,ans));
    ans=max(ans,left+right+root->val);
    return max(left,right)+root->val;
}
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        solve(root,ans);
        return ans;
    }
};



// Construct Binary Tree from Preorder and Inorder Traversal


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
TreeNode* solve(vector<int>& inorder, vector<int>& preorder,
int start,int end,int &index,unordered_map<int,int> &mp, int n){
    if(index>=n || start>end) return NULL;
    int element=preorder[index++];
    TreeNode* root=new TreeNode(element);
    int pos=mp[element];
    root->left=solve(inorder,preorder,start,pos-1,index,mp,n);
    root->right=solve(inorder,preorder,pos+1,end,index,mp,n);
    return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        int index=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        mp[inorder[i]]=i;
        return solve(inorder,preorder,0,n-1,index,mp,n);

    }
};


//  Construct Binary Tree from Inorder and Postorder Traversal


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
TreeNode* solve(vector<int>& inorder, vector<int>& postorder,int start,int end,int &index, int n,
unordered_map<int,int> &mp){
    if(index<0 || start>end)
    return NULL;
    int ele=postorder[index--];
    TreeNode* root=new TreeNode(ele);
    int pos=mp[ele];
    root->right=solve(inorder,postorder,pos+1,end,index,n,mp);
    root->left=solve(inorder,postorder,start,pos-1,index,n,mp);
    return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=postorder.size();
        int index=n-1;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        mp[inorder[i]]=i;
        return solve(inorder,postorder,0,n-1,index,n,mp);
    }
};
