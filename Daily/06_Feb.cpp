// Find the Index of the First Occurrence in a String


class Solution {
public:
    int strStr(string haystack, string needle) {
        int found=-1;
        found=haystack.find(needle);
        return found;
    }
};


// Minimum Characters required to make a String Palindromic


int Solution::solve(string A) {
    string s=A;
reverse(A.begin(),A.end());
s=s+'#'+A; //to avoid cases where full string is equal
int n =s.size();
vector<int>pi(n,0);
for(int i =1;i<n;i++){
int j =pi[i-1];
while(j>0&&s[i]!=s[j]){
j=pi[j-1];
}
if(s[i]==s[j]){
j++;
}
pi[i]=j;
}
return A.size()-pi[n-1];
}



// Valid Anagram


class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        
        for(int i=0;i<s.length();i++){
            if(s[i]!=t[i])
            return false;
        }
        return true;

    }
};



// Count and Say


class Solution {
public:
string solve(string s){
    int n=s.length();
    int i=0,j=0,count=0;
    string ans="";
    while(i<n){
        j=i;
        count=1;
        while(i<n && s[i]==s[i+1]){
            count++;
            i++;
        }
        ans+=(count+'0');
        ans+=s[j];
        i++;
    }
    return ans;
}
    string countAndSay(int n) {
       string s="1";
       n--;
       while(n--)
       s=solve(s);
       return s;
    }
};
