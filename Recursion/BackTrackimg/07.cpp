// Subsets


class Solution {
public:
void solve(vector<int> &arr,int i,vector<vector<int>> &ans, vector<int> &temp){
    if(i == arr.size()){
        ans.push_back(temp);
        return ;
    }
    temp.push_back(arr[i]);
    solve(arr,i+1,ans,temp);
    temp.pop_back();
    solve(arr,i+1,ans,temp);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(nums,0,ans,temp);
        return ans;
    }
};
