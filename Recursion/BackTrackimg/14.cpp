// Remove Invalid Parentheses


class Solution {
public:
int getlength(string s){
    stack<char> st;
    for(int i=0;i<s.size();i++){
        char ch=s[i];
        if(ch=='('){
            st.push('(');
        }
        else if(ch == ')'){
            if(st.size()>0 && st.top()=='(') st.pop();
            else st.push(')');
        }
    }
    return st.size();
}
void solve(string s,unordered_map<string,bool> &m,vector<string> &ans,int length){
    if(m[s]==true) return ;
    else m[s]=true;
    if(length==0){
        int newLength=getlength(s);
        if(newLength==0){
            ans.push_back(s);
        }
        return ;
    }
    for(int i=0;i<s.size();i++){
        string left = s.substr(0,i);
        string right = s.substr(i+1);
        string temp = left+right;
        solve(temp,m,ans,length-1);
    }
}
    vector<string> removeInvalidParentheses(string s) {
        int totalRemove = getlength(s);
        unordered_map<string,bool> m;
        vector<string> ans;
        solve(s,m,ans,totalRemove);
        return ans;
    }
};
