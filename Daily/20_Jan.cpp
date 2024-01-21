// Intersection of Two Linked Lists

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        int lenA = solve(headA);
        int lenB = solve(headB);
        if(lenA > lenB){
            while(lenA>lenB){
                headA=headA->next;
                lenA--;
            }
        }
        else if(lenB > lenA){
            while(lenB>lenA){
                headB=headB->next;
                lenB--;
            }
        }
        while(headA && headB){
            if(headA==headB) return headA;
            headA=headA->next;
            headB=headB->next;
        }
        return NULL;
    }
};


// Linked List Cycle


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL) return false;
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow) return true;
        }
        return false;
    }
};


// Reverse Nodes in k-Group

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return NULL;
        int n=solve(head);
        if(n<k) return head;
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* next=NULL;
        int count=0;
        while(count<k && curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }
        if(next!=NULL)
        head->next=reverseKGroup(curr,k);
        
        return prev;
    }
};
