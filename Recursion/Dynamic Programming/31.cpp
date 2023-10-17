// Minimum Cost Tree From Leaf Values


class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int res = 0;
        vector<int> s={INT_MAX};
        for(auto a:arr){
            while(s.back()<=a){
                int mid = s.back();
                s.pop_back();
                res+=mid*min(s.back(),a);
            }
            s.push_back(a);
        }
        for(int i=2;i<s.size();i++)
        res+=s[i]*s[i-1];

        return res;
    }
};
