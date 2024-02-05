// Reverse Words in a String


class Solution {
public:
    string reverseWords(string s) {
        vector<string> st;
        string temp="",ans="";
        int i=0;
        while(i<s.length()){
            if(s[i]==' ') temp="";
            while(s[i]!=' ' && i<s.length()){
                temp+=s[i];
                i++;
            }
            if(temp != "") st.push_back(temp);
            temp="";
            i++;
        }
        for(int i=st.size()-1;i>=0;i--){
            ans+=st[i];
            if(i!=0) ans+=' ';
        }
        return ans;
    }
};


// Longest Palindromic Substring


class Solution {
public:
bool solve(string &s,int i,int j){
    while(i<j){
        if(s[i]!=s[j])
        return false;
        i++;j--;
    }
    return true;
}
    string longestPalindrome(string s) {
        string ans;
        int n=s.length();
        int maxi=1;
        ans.push_back(s[0]);
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(solve(s,i,j)){
                    if(j-i+1 > maxi){
                        maxi=j-i+1;
                        ans=s.substr(i,maxi);
                    }
                }
            }
        }
        return ans;
    }
};



// Roman to Integer


class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int n=s.length(),ans=0;
        for(int i=0;i<n;i++){
            if(i<n && mp[s[i]] < mp[s[i+1]]){
                ans+=mp[s[i+1]]-mp[s[i]];
                i++;
            }
            else ans+=mp[s[i]];
        }
        return ans;
    }
};



// String to Integer (atoi)

class Solution {
public:
    int myAtoi(string s) {
        int i=0,n=s.length();
        bool flag = false;
        long long ans=0;
        while(s[i]==' ' && i<n){
            i++;
        }
        if(s[i]=='+')
        i++;
        else if(s[i]=='-'){
            flag=true;
            i++;
        }
        while(i<n){
            char ch=s[i];
            if(ch>='0' && ch<='9'){
                if(ans > LLONG_MAX/10 || (ans==LLONG_MAX/10 && (ch-'0') > LLONG_MAX%10))
                return (flag) ? INT_MIN:INT_MAX;
            
            ans=ans*10+(ch-'0');}
            else break;
            i++;
        }
        if(flag){
            ans=-ans;
            if(ans<INT_MIN) return INT_MIN;
        }
        else {
            if(ans>INT_MAX) return INT_MAX;
        }
        return ans;
    }
};
