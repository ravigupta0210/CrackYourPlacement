// Generate Parentheses


class Solution {
public:
void solve(vector<string> &ans,string &temp,int cOpen,int cClose,int rOpen,int rClose){
    if(rOpen == 0 && rClose == 0) {
        ans.push_back(temp);
        return ;
    }
    if(rOpen>0){
        temp.push_back('(');
        solve(ans,temp,cOpen+1,cClose,rOpen-1,rClose);
        temp.pop_back();
    }
    if(rClose>0 && cOpen > cClose){
        temp.push_back(')');
        solve(ans,temp,cOpen,cClose+1,rOpen,rClose-1);
        temp.pop_back();
    }
}
    vector<string> generateParenthesis(int n) {
        int cOpen = 1 , cClose = 0, rOpen = n-1,rClose = n;
        string temp ="(";
        vector<string> ans;
        solve(ans,temp,cOpen,cClose,rOpen,rClose);
        return ans;
    }
};
