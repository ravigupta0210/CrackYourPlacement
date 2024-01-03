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
