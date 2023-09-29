// Word Ladder


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n=beginWord.size();
        unordered_map<string,int> mp,vis;
        for(auto i:wordList)
        mp[i]=1;
        if(mp[endWord]!=1) return 0;
        queue<string> q;
        q.push(beginWord);
        vis[beginWord] = 1;
        int ans=0;
        while(!q.empty()){
            int len = q.size();
            while(len--){
                string u=q.front();
                q.pop();
                if(u==endWord) return ans+1;
                for(int i=0;i<n;i++){
                    for(char ch='a';ch<='z';ch++){
                        string v=u;
                        v[i]=ch;
                        if(!vis[v] && mp[v]){
                            q.push(v);
                            vis[v]=1;
                        }
                    }
                }
            }
            ans++;
        }
        return 0;
    }
};
