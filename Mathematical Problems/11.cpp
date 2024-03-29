// Valid Square


class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        if(p1 == p2 || p1 == p3 || p1 == p4 || p2 == p3 || p2 == p4 || p3 == p4) return false;

        unordered_map<int,int> mp;
        int a = pow(p1[0] - p2[0],2) + pow(p1[1]-p2[1],2);
        int b = pow(p1[0] - p3[0],2) + pow(p1[1]-p3[1],2);
        int c = pow(p1[0] - p4[0],2) + pow(p1[1]-p4[1],2);
        int d = pow(p2[0] - p3[0],2) + pow(p2[1]-p3[1],2);
        int e = pow(p2[0] - p4[0],2) + pow(p2[1]-p4[1],2);
        int f = pow(p3[0] - p4[0],2) + pow(p3[1]-p4[1],2);
        mp[a]++,mp[b]++,mp[c]++,mp[d]++,mp[e]++,mp[f]++;

        if(mp.size() > 2) return false;
        else return true;
    }
};
