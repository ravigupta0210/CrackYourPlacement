// Reverse Pairs


class Solution {
public:
//here our approach is to do mergesort and cnt the pair

int cnt=0;
void mergeSort(int low,int mid,int high,vector<int>& nums){
    int j=mid+1;
    for(int i=low;i<=mid;i++){
        while(j<= high && nums[i] > 2*(long long)nums[j])
        j++;
        cnt+=j-(mid+1);
    }
    vector<int> temp;
    int left=low,right=mid+1,k=0;
    while(left<=mid && right<=high){
        if(nums[left]<nums[right])
        temp.push_back(nums[left++]);
        else
        temp.push_back(nums[right++]);
    }
    while(left<=mid)
    temp.push_back(nums[left++]);

    while(right<=high)
    temp.push_back(nums[right++]);

    int x=0;
    for(int m=low;m<=high;m++){
        nums[m]=temp[m-low];
    }
}
//so here we made some changes in syntax
void merge(int low,int high,vector<int>& nums){
    if(low==high) return;
    int mid= (low+high)/2;
    merge(low,mid,nums);
    merge(mid+1,high,nums);
    mergeSort(low,mid,high,nums);
}
    int reversePairs(vector<int>& nums) {
        merge(0,nums.size()-1,nums);
        return cnt;
    }
};
