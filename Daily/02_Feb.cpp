// LFU Cache


class LFUCache {
public:
priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
    unordered_map<int,int>mp;
    unordered_map<int,int>freq;
    int cap;
    int tar;
    LFUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        put(key,mp[key]);
        return mp[key];
    }
    
    void put(int key, int value) {
        if(cap == 0) return ;
        if(mp.find(key)==mp.end() && mp.size()==cap){
            while(mp.size()==cap){
                auto temp=pq.top();
                if(freq[temp.second.second] == temp.first){
                    mp.erase(temp.second.second);
                    freq.erase(temp.second.second);
                }
                pq.pop();
            }
        }
        mp[key]=value;
        freq[key]++;
        pq.push({freq[key],{tar++,key}});
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */



// Largest Rectangle in Histogram


class Solution {
public:
vector<int> nextSmaller(vector<int> arr,int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for(int i=n-1;i>=0;i--){
        int curr=arr[i];
        while(s.top()!=-1 && arr[s.top()]>=curr)
        s.pop();
        ans[i]=s.top();
        s.push(i);
        
    }
    return ans;
}
vector<int> prevSmaller(vector<int> arr,int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        int curr=arr[i];
        while(s.top()!=-1 && arr[s.top()]>=curr)
        s.pop();
        ans[i]=s.top();
        s.push(i);
        
    }
    return ans;
}
    int largestRectangleArea(vector<int>& height) {
        int n=height.size();
        vector<int> next(n),prev(n);
        next=nextSmaller(height,n);
        prev=prevSmaller(height,n);
        int area=INT_MIN;
        for(int i=0;i<n;i++){
            int l=height[i];
            if(next[i]==-1)
            next[i]=n;
            int b=next[i]-prev[i]-1;
            int newArea=l*b;
            area=max(area,newArea);
        }
        return area;
    }
};
