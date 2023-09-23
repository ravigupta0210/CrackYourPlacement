// All Nodes Distance K in Binary Tree


class Solution {
public:
bool rootToTarget(vector<TreeNode*>& path,TreeNode* root,TreeNode* target){
    if(root==NULL) return false;
    path.push_back(root);
    if(root==target) return true;
    if(rootToTarget(path,root->left,target) || rootToTarget(path,root->right,target)) return true;
    path.pop_back();
    return false;
}
void solve(TreeNode* root, int k,vector<int> &ans,TreeNode* blocker){
    if(root == NULL || k<0 || root==blocker) return ;
    if(k==0){
        ans.push_back(root->val);
        return ;
    }
    solve(root->left,k-1,ans,blocker);
    solve(root->right,k-1,ans,blocker);
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<TreeNode*> path;
        rootToTarget(path,root,target);
        reverse(path.begin(),path.end());
        vector<int> ans;
        TreeNode* blocker =NULL;
        for(int i=0;i<path.size();i++){
            solve(path[i],k-i,ans,blocker);
            blocker = path[i];
        }
 return ans;
    }
};
