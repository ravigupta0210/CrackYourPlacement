// Word Break


class Solution {
public:
bool solve(int i,string s,vector<string>& wordDict){
    if(i==s.length()) return true;
    for(int j=0;j<wordDict.size();j++){
        string a=wordDict[j];
        if(s.substr(i,a.size()) == a && solve(i+a.size(),s,wordDict))
        return true;
    }
    return false;
}
    bool wordBreak(string s, vector<string>& wordDict) {
        return solve(0,s,wordDict);
    }
};
