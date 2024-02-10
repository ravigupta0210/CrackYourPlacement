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


// Predecessor and Successor


//{ Driver Code Starts
// C++ program to find predecessor and successor in a BST
#include "bits/stdc++.h"
using namespace std;

// BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};


// } Driver Code Ends
/* BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
class Solution
{
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        while(root){
            if(root->key==key){
                if(root->left){
                    Node* temp=root->left;
                    while(temp->right){
                        temp=temp->right;
                    }
                    pre=temp;
                }
                if(root->right){
                    Node* temp=root->right;
                    while(temp->left)
                    temp=temp->left;
                    suc=temp;
                }
                break;
            }
            if(root->key > key){
                suc=root;
                root=root->left;
            }
            else{
                pre=root;
                root=root->right;
            }
        }
    }
};

//{ Driver Code Starts.

Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}
// Driver program to test above functions
int main() {
   
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
        getline(cin, s);
        Node* root = buildTree(s);
        getline(cin, s);
        int k = stoi(s);
        Node *pre=NULL,*succ=NULL;
        Solution ob;
        ob.findPreSuc(root,pre,succ,k);
        (pre!=NULL)?cout<<pre->key:cout<<-1;
        cout<<" ";
        (succ!=NULL)?cout<<succ->key:cout<<-1;
        cout<<endl;
        // inOrderTraversal(root);
   }
   return 0;
}
// } Driver Code Ends
