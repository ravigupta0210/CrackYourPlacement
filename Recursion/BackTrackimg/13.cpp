// Distribute Repeating Integers


class Solution {
public:
bool solve(int i, map<int,int> &count,vector<int>& quantity){
    if(i>=quantity.size()) return true;
    for(auto it=count.begin();it!=count.end();it++){
        if(it->second >= quantity[i]){
            count[it->first]-=quantity[i];
            if(solve(i+1,count,quantity)) return true;
            count[it->first]+=quantity[i];
        }
    }
    return false;
}
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
      map<int,int> count;
      for(int i=0;i<nums.size();i++)
      count[nums[i]]++;
      sort(quantity.begin(),quantity.end(),greater<int>());
      return solve(0,count,quantity);  
    }
};
