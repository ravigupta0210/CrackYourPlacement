// Jump Game


class Solution {
public:
    bool canJump(vector<int>& nums) {
        //here we approach by two ways from front and back
        //front 
        // int n=nums.size();
        // int maxi=0;
        // for(int i=0;i<n;i++){
        //     if(i>maxi) return false;
        //     maxi=max(maxi,i+nums[i]);
        // }
        // return true;



        // back
        int left=nums.size()-1;
        for(int i=nums.size()-2;i>=0;i--){
            if(i+nums[i] >= left) left=i;

        }
        if(left==0) return true;
        else return false;
    }
};
