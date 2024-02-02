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
