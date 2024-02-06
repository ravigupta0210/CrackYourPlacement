// Find the Index of the First Occurrence in a String


class Solution {
public:
    int strStr(string haystack, string needle) {
        int found=-1;
        found=haystack.find(needle);
        return found;
    }
};
