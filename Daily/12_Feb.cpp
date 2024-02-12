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


// Distinct Numbers in Window

vector<int> Solution::dNums(vector<int> &A, int B) {
    vector<int> ans;
    unordered_map<int,int> mp;
    queue<int> q;
    if(B>A.size())
    return ans;
    for(int i=0;i<B;i++){
        q.push(A[i]);
        mp[A[i]]++;
    }
    ans.push_back(mp.size());
    for(int i=B;i<A.size();i++){
        int frontElement = q.front();
        q.pop();
        if(mp[frontElement]>1) mp[frontElement]--;
        else mp.erase(frontElement);
        q.push(A[i]);
        mp[A[i]]++;
        ans.push_back(mp.size());
    }
    return ans;
}


// Kth Largest Element in an Array

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxi;
        for(auto i:nums)
        maxi.push(i);

        while(k>1){
            k--;
            maxi.pop();
        }
        return maxi.top();
    }
};



// Flood Fill


class Solution {
public:
int row[4]={-1,1,0,0};
int col[4]={0,0,-1,1};
void dfs(vector<vector<int>>& image, int sr, int sc, int color,int incolor,vector<vector<int>> &ans){
    ans[sr][sc]=color;
    int n=image.size(),m=image[0].size();
    
    for(int i=0;i<4;i++){
        int newx=sr+row[i],newy=sc+col[i];
        if(newx>=0 && newx<n && newy>=0 && newy<m && image[newx][newy]==incolor && ans[newx][newy]!=color)
        dfs(image,newx,newy,color,incolor,ans);
    }
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans=image;
        int incolor = image[sr][sc];
        dfs(image,sr,sc,color,incolor,ans);
        return ans;
    }
};
