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
