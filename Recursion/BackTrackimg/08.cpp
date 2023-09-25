// Binary Tree Paths


class Solution {
public:
void solve(TreeNode* root,string &temp,vector<string> &ans){
    if(root == NULL) return ;
    if(root->left == NULL && root->right == NULL){
         string oldTemp = temp;   
        temp+=to_string(root->val);
        ans.push_back(temp);
         temp = oldTemp;   
        return ;

    }
    string oldTemp = temp;
    temp += to_string(root->val);
    temp.push_back('-');
    temp.push_back('>');
    solve(root->left,temp,ans);
    solve(root->right,temp,ans);
    temp = oldTemp;
}
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string temp="";
        solve(root,temp,ans);
        return ans;
    }
};
