// Minimum Number of Steps to Make Two Strings Anagram


class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> mp;
        for(auto ch:t)
        mp[ch]++;

        int count=0;
        for(auto ch:s){
             if(mp.find(ch) != mp.end() && mp[ch]>0){
                count++;
                mp[ch]--;
             }
            }
        
        return s.length()-count;
    }
};


// Find and Replace Pattern


class Solution {
public:
string change(string word){
    unordered_map<char,char> mp;
    char ch = 'a';
    for(int i=0;i<word.length();i++){
        if(mp.find(word[i]) == mp.end()){
            mp[word[i]] = ch;
            ch++;
        }
    }
    for(int i=0;i<word.length();i++){
        word[i] = mp[word[i]];
    }
    return word;
}
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        pattern = change(pattern);
        vector<string> ans;
        for(auto word: words){
            if(pattern == change(word))
            ans.push_back(word);
        }
        return ans;
    }
};


// Remove All Occurrences of a Substring

class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.length()!=0 && s.find(part) < s.length()){
            s.erase(s.find(part),part.length());
        }
        return s;
    }
};


// Lexicographically Smallest Equivalent String

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<char> v(26);
        for(char i='a';i<='z';i++) v[i-'a'] = i;
        for(int k=0;k<4;k++){
            for(int i=0;i<s1.length();i++){
                v[s2[i]-'a'] = min(v[s2[i]-'a'],v[s1[i]-'a']);
                v[s1[i]-'a'] = min(v[s2[i]-'a'],v[s1[i]-'a']);
            }
        }
        for(int i=0;i<baseStr.length();i++){
            baseStr[i] = v[baseStr[i]-'a'];
        }
        return baseStr;
    }
};
