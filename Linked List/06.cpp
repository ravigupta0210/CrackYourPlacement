// Reverse Linked List


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* forward = NULL;
        ListNode* prev = NULL;
        ListNode* curr= head;
        while(curr!=NULL){
            forward = curr->next;
            curr->next = prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
};
