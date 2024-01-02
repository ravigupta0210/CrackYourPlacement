// Partitioning Into Minimum Number Of Deci-Binary Numbers

class Solution {
public:
    int minPartitions(string n) {
        int maxi = INT_MIN;
        for(int i=0;i<n.length();i++){
            maxi = max(maxi,int(n[i]));
        }
        return maxi-48;
    }
};

// Encode and Decode TinyURL

class Solution {
public:
    map<string,string> mp;
    int n=0;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string res = "http://tinyurl.com/" + to_string(n);
        n++;
        mp[res] = longUrl;
        return res;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));


// Execution of All Suffix Instructions Staying in a Grid

class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> ans;
        int count = 0;
        int row,col;
        for(int i=0;i<s.length();i++){
            count = 0;
            row = startPos[0];
            col = startPos[1];
            for(int j=i;j<s.length();j++){
                char ch = s[j];
                if(ch == 'L')
                col--;
                else if(ch == 'R')
                col++;
                else if(ch == 'U')
                row--;
                else row++;
                if(row >= 0 && row <= n-1 && col >=0 && col<= n-1)
                count++;
                else break;
            }
            ans.push_back(count);
        }
        return ans;
    }
};

// Partition Labels

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++)
        mp[s[i]] = i;
        int j=0;
        int maxi = 0;
        vector<int> ans;
        for(int i=0;i<s.size();i++){
            maxi = max(maxi,mp[s[i]]);
            if(i==maxi){
                ans.push_back(i-j+1);
                j=i+1;
            }
        }
        return ans;

    }
};


// Optimal Partition of String

class Solution {
public:
    int partitionString(string s) {
        unordered_map<char,int> mp;
        int count=1;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i]) != mp.end()){
                mp.clear();
                count++;
            }
            mp[s[i]]++;
        }
        return count;
    }
};
