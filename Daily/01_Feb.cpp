// Nearest Smaller Element


vector<int> Solution::prevSmaller(vector<int> &A) {
    int n=A.size();
    vector<int> ans(n,-1);
    stack<int> st;
    st.push(A[0]);
    for(int i=1;i<n;i++){
        if(A[i]>st.top()){
            ans[i]=st.top();
            st.push(A[i]);
        }
        else{
            while(!st.empty() && st.top()>=A[i])
            st.pop();
        
        if(!st.empty())
        ans[i]=st.top();
        st.push(A[i]);
    }
}
    return ans;
}


// LRU Cache



class LRUCache {
public:
class Node{
    public:
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int x,int y){
        key=x;
        val=y;
    }
};
Node* head = new Node(-1,-1);
Node* tail = new Node(-1,-1);
int cap;
unordered_map<int,Node*> mp;

void addnode(Node* newnode){
    Node* temp=head->next;
    newnode->next=temp;
    newnode->prev=head;
    temp->prev=newnode;
    head->next=newnode;
}
void deletenode(Node* delnode){
    Node* delprev=delnode->prev;
    Node* delnext=delnode->next;
    delprev->next=delnext;
    delnext->prev=delprev;
}
    LRUCache(int capacity) {
        cap=capacity;
        head->next = tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            Node* res = mp[key];
            int ans=res->val;
            mp.erase(key);
            deletenode(res);
            addnode(res);
            mp[key]=head->next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* existNode = mp[key];
            mp.erase(key);
            deletenode(existNode);
        }
        if(mp.size()==cap){
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new Node(key,value));
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
