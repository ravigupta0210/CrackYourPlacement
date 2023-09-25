// Sum of All Subset XOR Totals


class Solution {
public:
void solve(vector<int> &arr,int &sum,int &xorAns,int i){
    if(i==arr.size()){
        sum+=xorAns;
        return ;
    }
    xorAns = arr[i]^xorAns;
    solve(arr,sum,xorAns,i+1);
    xorAns = arr[i]^xorAns;
    solve(arr,sum,xorAns,i+1);
}
    int subsetXORSum(vector<int>& nums) {
        int sum = 0;
        int xorAns = 0;
        solve(nums,sum,xorAns,0);
        return sum;
    }
};
