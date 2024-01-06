// Design Underground System


class UndergroundSystem {
public:
unordered_map<int,pair<string,int>> mp1;
unordered_map<string,pair<double,int>> mp2;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        mp1[id] = {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto checkIn = mp1[id];
        mp1.erase(id);
        string routeName = checkIn.first + "_" + stationName;
        mp2[routeName].first += t-checkIn.second;
        mp2[routeName].second += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string routeName = startStation + "_" + endStation;
        auto& ans = mp2[routeName];
        return ans.first/ans.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */



// Display Table of Food Orders in a Restaurant


class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<pair<string,string>,int> food;
        set<int> tables;
        set<string> foodItems;
        for(auto order:orders){
            tables.insert(stoi(order[1]));
            foodItems.insert(order[2]);
            pair<string,string> temp = {order[2],order[1]};
            food[temp]++;
        }
        vector<string> header;
        header.push_back("Table");
        for(auto foodi : foodItems)
        header.push_back(foodi);

        vector<vector<string>> ans;
        ans.push_back(header);
        for(auto table:tables){
            vector<string> v;
            v.push_back(to_string(table));
            for(int i=1;i<ans[0].size();i++){
                string name = ans[0][i];
                v.push_back(to_string(food[{name,to_string(table)}]));
            }
            ans.push_back(v);
        }
        return ans;
    }
};
