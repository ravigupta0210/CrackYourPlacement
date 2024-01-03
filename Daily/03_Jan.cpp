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
