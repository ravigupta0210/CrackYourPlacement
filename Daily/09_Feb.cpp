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


// Symmetric Tree


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
bool solve(TreeNode* root1,TreeNode* root2){
    if(root1==NULL && root2==NULL) return true;
    else if(root1==NULL && root2!=NULL) return false;
    else if(root1!=NULL && root2==NULL) return false;
    if(root1->val!=root2->val) return false;
    return solve(root1->left,root2->right) && solve(root1->right,root2->left);
}
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return solve(root->left,root->right);
    }
};



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
    while(root->right!=NULL)
    root=root->right;
    return root;
}
    void flatten(TreeNode* root) {
        TreeNode* curr=root;
        while(curr!=NULL){
            if(curr->left){
                TreeNode* pred=solve(curr);
                pred->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
            }
            curr=curr->right;
        }
    }
};





//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

/* Helper function to test mirror(). Given a binary
   search tree, print out its data elements in
   increasing sorted order.*/
void inOrder(struct Node *node) {
    if (node == NULL) return;

    inOrder(node->left);
    printf("%d ", node->data);

    inOrder(node->right);
}


// } Driver Code Ends
// function Template for C++

/* A binary tree node has data, pointer to left child
   and a pointer to right child /
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        if(node==NULL) return ;
        mirror(node->left);
        mirror(node->right);
        Node* temp=node->right;
        node->right=node->left;
        node->left=temp;
    }
};




// Mirror Tree



//{ Driver Code Starts.

/* Driver program to test size function*/
int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string str;
        getline(cin, str);
        Node *root = buildTree(str);
        Solution ob;
        ob.mirror(root);
        inOrder(root);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends



//  Children Sum Property



#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void changeTree(BinaryTreeNode < int > * root) {
    if(root==NULL) return ;
    int child=0;
    if(root->left) child+=root->left->data;
    if(root->right) child+=root->right->data;
    if(child<root->data){
        if(root->left){
                root->left->data+=root->data-child;
        }
        else if(root->right){
                root->right->data+=root->data-child;
        }
    }
    else{
        root->data=child;
    }
    changeTree(root->left);
    changeTree(root->right);

    if(root->left!=NULL || root->right!=NULL){
        int total=0;
        if(root->left)total+=root->left->data;
        if(root->right)total+=root->right->data;
        root->data=total;
    }
}  
