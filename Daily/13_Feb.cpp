// Clone Graph


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
Node* dfs(unordered_map<Node*,Node*> &mp,Node* node){
    vector<Node*> neigh;
    Node* clone=new Node(node->val);
    mp[node]=clone;
    for(auto it:node->neighbors){
        if(mp.find(it)!=mp.end()){
            neigh.push_back(mp[it]);
        }
        else neigh.push_back(dfs(mp,it));
    }
    clone->neighbors = neigh;
    return clone;
}
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> mp;
        if(node==NULL) return NULL;
        if(node->neighbors.size()==0){
            Node* clone = new Node(node->val);
            return clone;
        }
        return dfs(mp,node);
    }
};
