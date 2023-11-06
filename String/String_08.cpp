// Simplify Path


class Solution {
public:
    string simplifyPath(string path) {
        int i=0;
        string ans="";
        stack<string> st;
        while(i < path.length()){
            if(path[i] == '/') {
                i++;
                continue;
            }
            string temp="";
            while(i<path.length() && path[i] != '/'){
                temp.push_back(path[i]);
                i++;
            }
            if(temp == ".") continue;
            else if(temp == ".." && st.empty()) continue;
            else if(temp == ".." && !st.empty()) st.pop();
            else st.push(temp); 
        }
        
        while(!st.empty()){
            ans = '/' + st.top() + ans;
            st.pop();
        }
        if(ans.length() == 0) return "/";
        else return ans;
    }
};
