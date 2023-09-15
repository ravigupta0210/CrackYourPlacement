// Find Kth Bit in Nth Binary String



class Solution {
public:
string invert(string s){
    for(int i=0;i<s.size();i++){
        if(s[i] == '1')
        s[i] = '0';
        else s[i] = '1';
    }
    return s;
}
string solve(int n){
    if(n==1) return "0";
    string s = solve(n-1);

   string rev =  invert(s);
    reverse(rev.begin(),rev.end());

    return s + "1" + rev;
}
    char findKthBit(int n, int k) {
        string ans = solve(n);
        return ans[k-1];
    }
};
