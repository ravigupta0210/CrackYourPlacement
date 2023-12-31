class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp = head;
        while(temp->next != NULL){
            int gcd = __gcd(temp->val,temp->next->val);
            ListNode* insertnode = new ListNode(gcd);
            ListNode* extra = temp->next;
            temp->next = insertnode;
            insertnode->next=extra;
            temp = extra;
        }
        return head;
    }
};


// Queries on a Permutation With Key

class Solution {
public:
int findSolve(int key,vector<int> p){
    for(int i=0;i<p.size();i++){
        if(key == p[i]){
            return i;
        }
    }
    return 0;
}
vector<int> refactor(vector<int> p,int key){
    vector<int> temp ;
    temp.push_back(key);
    for(int i=0;i<p.size();i++){
        if(key != p[i])
        temp.push_back(p[i]);
    }
    return temp;
}
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> p;
        for(int i=1;i<=m;i++)
        p.push_back(i);

        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int index = findSolve(queries[i],p);
            ans.push_back(index);
            p = refactor(p,queries[i]);
        }
        return ans;
    }
};
