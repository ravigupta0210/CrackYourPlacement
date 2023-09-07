// Evaluate Division


class Solution {
public:
unordered_map<string,unordered_map<string,double>> buildGrapgh(vector<vector<string>>& equations, vector<double>& values){
    unordered_map<string,unordered_map<string,double>> gr;
    for(int i=0;i<equations.size();i++){
        string divident = equations[i][0];
        string divisor = equations[i][1];
        double value = values[i];

        gr[divident][divisor] = value;
        gr[divisor][divident] = 1.0/value;

    }
    return gr;
}

void dfs(string node,string &dest, double temp, double &ans,unordered_set<string> &vis, unordered_map<string,unordered_map<string,double>> &gr ){
    if(vis.find(node) != vis.end()) return ;

    vis.insert(node);
    if(node == dest){
        ans = temp;
        return ;
    }

    for(auto negh : gr[node]){
        dfs(negh.first,dest,temp*negh.second,ans,vis,gr);
    }
}
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> finalAns;
        unordered_map<string,unordered_map<string,double>> gr =buildGrapgh(equations,values);

        for(auto query:queries){
            string divident = query[0];
            string divisor = query[1];

            if(gr.find(divident) == gr.end() || gr.find(divisor) == gr.end())
            finalAns.push_back(-1.0);
            else{
                unordered_set<string> vis;
                double ans=-1,temp=1.0;
                dfs(divident,divisor,temp,ans,vis,gr);
                finalAns.push_back(ans);
            }

        }
        return finalAns;
    }
};
