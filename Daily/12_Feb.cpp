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


// Find Median from Data Stream

class MedianFinder {
public:
int n;
double median;
priority_queue<int> left;
priority_queue<int,vector<int>,greater<int>> right;
    MedianFinder() {
        n=0;
    }
    
    void addNum(int num) {
        if(!left.empty() && left.top()>num){
            left.push(num);
            if(left.size()>right.size()+1){
                right.push(left.top());
                left.pop();
            }
        }
        else{
            right.push(num);
            if(right.size()>left.size()+1){
                left.push(right.top());
                right.pop();
            }
        }
        n++;
    }
    
    double findMedian() {
        if(n&1)
        {if(left.size()>right.size())
        return left.top();
        else return right.top();}
        else return (left.top()+right.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


// Kth Largest Element in a Stream


class KthLargest {
public:
int n;
priority_queue<int,vector<int>,greater<int>> mini;
    KthLargest(int k, vector<int>& nums) {
        n=k;
        for(auto i:nums)
        mini.push(i);
    }
    
    int add(int val) {
        mini.push(val);
        while(mini.size()>n)
        mini.pop();
        return mini.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
