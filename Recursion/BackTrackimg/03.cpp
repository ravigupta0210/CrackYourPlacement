// Letter Tile Possibilities


class Solution {
public:
void solve(int level,int &count,unordered_map<char,int> &mp,int n){
    count++;
    if(level==n) return ;

    for(auto v:mp){
        if(v.second!=0){
            mp[v.first]--;
            solve(level+1,count,mp,n);
            mp[v.first]++;
        }
    }
}
    int numTilePossibilities(string tiles) {
        int count = 0;
        unordered_map<char,int> mp;
        int n=tiles.size();
        for(int i=0;i<n;i++)
        mp[tiles[i]]++;
        solve(0,count,mp,n);
        return count-1;
    }
};
