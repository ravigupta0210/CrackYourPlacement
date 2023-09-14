// Predict the Winner


class Solution {
public:
int solve(vector<int>& nums,int i,int j){
    if(i>j) return 0;
    if(i==j) return nums[i];
    int option1 = nums[i]+min(solve(nums,i+1,j-1),solve(nums,i+2,j));
    int option2 = nums[j]+min(solve(nums,i+1,j-1),solve(nums,i,j-2));

    return max(option1,option2);
}
    bool predictTheWinner(vector<int>& nums) {
        int p1 = solve(nums,0,nums.size()-1);
        int total = 0;
        for(int i=0;i<nums.size();i++)
        total+=nums[i];
        int p2 = total-p1;
        if(p1>=p2) return true;
        else return false;
    }
};
