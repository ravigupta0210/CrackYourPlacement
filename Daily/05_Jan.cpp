// Subdomain Visit Count


class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> ans;
        map<string,int> mp;
        for(auto s:cpdomains){
            int i=0,cnt=0;
            while(isdigit(s[i]))
            cnt = cnt*10 + (s[i++]-'0');
            mp[s.substr(i+1)] += cnt;
            while(i<s.size()){
                if(s[i++]== '.')
                mp[s.substr(i)] += cnt;
            }
        }
        for(auto map:mp)
        ans.push_back(to_string(map.second)+" "+map.first);
        return ans;
    }
};
