// Minimum Number of Operations to Move All Balls to Each Box

class Solution {
public:
    vector<int> minOperations(string boxes) {
       vector<int> res;
       int ans;
       for(int i=0;i<boxes.length();i++){
           ans=0;
           for(int j=0;j<boxes.length();j++){
               if(boxes[j]=='1')
               ans += abs(i-j);
           }
           res.push_back(ans);
       } 
       return res;
    }
};
