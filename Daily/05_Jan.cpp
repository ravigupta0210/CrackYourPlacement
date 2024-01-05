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


// Construct Smallest Number From DI String


class Solution {
public:
    string smallestNumber(string pattern) {
       string ans = "";
       int i=0;
       char ch = '1';
       stack<char> st;
       st.push(ch);
       int n = pattern.size();
       while(!st.empty() && i< n){
           ch++;
           if(pattern[i] == 'I'){
           while(!st.empty()){
               ans+=st.top();
               st.pop();
           }
           st.push(ch);
           }
           else{
               st.push(ch);
           }
           i++;
       } 
       while(!st.empty()){
           ans+=st.top();
           st.pop();
       }
       return ans;
    }
};


// Find Unique Binary String


class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans;
        int index = 0;
        for(auto binary:nums){
            ans+=to_string('1'-binary[index++]);
        }
        return ans;
    }
};
