// Sum of nodes within k distance from target


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/

class Solution{
public:
void mapping(unordered_map<Node*,Node*> &parent,Node* root){
    if(root==NULL) return ;
    if(root->left!=NULL){
        parent[root->left]=root;
    }
    if(root->right!=NULL){
        parent[root->right]=root;
    }
    mapping(parent,root->left);
    mapping(parent,root->right);
}
Node* search(Node* root,int target){
    if(root==NULL) return NULL;
    if(root->data == target) return root;
    
    Node* leftAns = search(root->left,target);
    if(leftAns!=NULL) return leftAns;
    Node* rightAns = search(root->right,target);
    if(rightAns!=NULL) return rightAns;
    
}
void solve(unordered_map<Node*,Node*> &parent,unordered_map<Node*,bool> &visited,Node* find,int &ans,int k){
    if(k<0 || find == NULL || visited[find] == true) return ;
    ans+=find->data;
    visited[find] = true;
    
    solve(parent,visited,find->left,ans,k-1);
    solve(parent,visited,find->right,ans,k-1);
    solve(parent,visited,parent[find],ans,k-1);
}
    int sum_at_distK(Node* root, int target, int k)
    {
        unordered_map<Node*,Node*> parent;
        parent[root] = NULL;
        mapping(parent,root);
        Node* find = search(root,target);
        int ans = 0;
        unordered_map<Node*,bool> visited;
        solve(parent,visited,find,ans,k);
        return ans;
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int target,k;
        cin>> target >> k;
        getchar();
        
        Solution ob;
        cout<< ob.sum_at_distK(root,target,k) << endl;
    }
	return 0;
}


// } Driver Code Ends
