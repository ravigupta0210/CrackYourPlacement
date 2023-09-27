// Word Break II


class Solution {
public:
void solve(string s,unordered_set<string> &st,vector<string> &ans,string temp,int index){
    if(index==s.length()){
        temp.pop_back();
        ans.push_back(temp);
        return ;
    }
    string subString="";
    for(int i=index;i<s.length();i++){
        subString.push_back(s[i]);
        if(st.count(subString))
        solve(s,st,ans,temp+subString+" ",i+1);
    }
}
    vector<string> wordBreak(string s, vector<string>& wordDict) {
       unordered_set<string> st;
        vector<string> result;
        for(auto i:wordDict)
        st.insert(i);
        string temp="";
        solve(s,st,result,temp,0);
        return result;
    }
};
