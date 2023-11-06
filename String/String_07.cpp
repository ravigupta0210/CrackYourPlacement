// Generate Parentheses


class Solution {
public:
void solve(int copen,int cclose,int ropen,int rclose,string& temp,vector<string>& ans){
    if(ropen == 0 && rclose == 0){
        ans.push_back(temp);
        return ;
    }
    if(ropen > 0){
        temp.push_back('(');
        solve(copen+1,cclose,ropen-1,rclose,temp,ans);
        temp.pop_back();
    }
    if(rclose > 0 && copen > cclose){
        temp.push_back(')');
        solve(copen,cclose+1,ropen,rclose-1,temp,ans);
        temp.pop_back();
    }
}
    vector<string> generateParenthesis(int n) {
        string temp="(";
        int copen=1,cclose=0,ropen=n-1,rclose=n;
        vector<string> ans;
        solve(copen,cclose,ropen,rclose,temp,ans);
        return ans;
    }
};
