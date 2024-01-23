// Rotate List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
int solve(ListNode* head){
    int len=0;
    while(head){
        head=head->next;
        len++;
    }
    return len;
}
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        int len = solve(head);
        k=k%len;
        ListNode* slow = head;
        ListNode* fast = head;
        while(k--)
        fast=fast->next;
        if(fast==NULL) return head;
        while(fast->next){
            fast=fast->next;
            slow=slow->next;
        }
        fast->next=head;
        head=slow->next;
        slow->next=NULL;
        return head;
    }
};


// Copy List with Random Pointer

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
unordered_map<Node*,Node*> mp;
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        if(mp.count(head)) return mp[head];
        Node* newNode = new Node(head->val);
        mp[head] = newNode;
        newNode->next = copyRandomList(head->next);
        newNode->random = copyRandomList(head->random);
        return newNode;
    }
};
