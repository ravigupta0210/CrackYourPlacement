//  Floor in BST


#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int floorInBST(TreeNode<int> * root, int X)
{
    int ans=-1;
    while(root){
        if(root->val==X)
        return root->val;
        else if(root->val>X)
        root=root->left;
        else{
        ans=root->val;
        root=root->right;
        }
    }
    return ans;
}


//  Ceil from BST



#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

int findCeil(BinaryTreeNode<int> *root, int x){
    int ans=-1;
    while(root){
        if(root->data==x) return root->data;
        else if(root->data<x)
        root=root->right;
        else{
            ans=root->data;
            root=root->left;
        }
    }
    return ans;
}
