// Populating Next Right Pointers in Each Node


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
void solve2(Node* curr,Node* left){
    while(curr!=NULL){
        left->next=curr->right;
        left=left->next;
        curr=curr->next;
        if(curr!=NULL){
            left->next=curr->left;
            left=left->next;
        }
    }
}
void solve(Node* curr){
if(curr->left==NULL) return ;
solve2(curr,curr->left);
solve(curr->left);

}
    Node* connect(Node* root) {
        if(root==NULL) return root;
        solve(root);
        return root;
    }
};



// Search in a Binary Search Tree


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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL) return NULL;
        if(root->val==val) return root;
        if(val<root->val)
        return searchBST(root->left,val);
        else return searchBST(root->right,val);
    }
};


// Convert Sorted Array to Binary Search Tree



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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return NULL;
        if(n==1) return new TreeNode(nums[0]);
        int middle=n/2 ;
        TreeNode* root=new TreeNode(nums[middle]);
        vector<int> left(nums.begin(),nums.begin()+middle);
        vector<int> right(nums.begin()+middle+1,nums.end());
        root->left=sortedArrayToBST(left);
        root->right=sortedArrayToBST(right);
        return root;
    }
};



// Construct Binary Search Tree from Preorder Traversal


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
TreeNode* solve(vector<int>& preorder,int maxi,int &index){
    if(index>=preorder.size()) return NULL;
    if(maxi<preorder[index]) return NULL;

    TreeNode* root=new TreeNode(preorder[index++]);
    root->left=solve(preorder,root->val,index);
    root->right=solve(preorder,maxi,index);
    return root;
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index=0;
        return solve(preorder,INT_MAX,index);
    }
};



// Validate Binary Search Tree


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
bool solve(TreeNode* root,long long mini,long long maxi){
    if(root== NULL) return true;
    if(root->val>mini && root->val<maxi){
        return (solve(root->left,mini,root->val) && solve(root->right,root->val,maxi));
    }
    else return false;
}
    bool isValidBST(TreeNode* root) {
        long long int mini=-1000000000000,maxi=1000000000000;
        return solve(root,mini,maxi);
    }
};


// Lowest Common Ancestor of a Binary Search Tree



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        if(root->val<p->val && root->val<q->val) return lowestCommonAncestor(root->right,p,q);
        else if(root->val>p->val && root->val>q->val) return lowestCommonAncestor(root->left,p,q);
        return root;
    }
};
