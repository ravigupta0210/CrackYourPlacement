// Remove Nodes From Linked List


class Solution {
public:
ListNode* reverseList(ListNode* head){
    ListNode* curr = head, *prev = NULL, *forward = NULL;
    while(curr){
        forward = curr->next;
        curr->next = prev ;
        prev = curr;
        curr= forward;

    }
    return prev;
}
    ListNode* removeNodes(ListNode* head) {
        head =  reverseList(head);
        ListNode* temp = head;
        while(temp->next){
            if(temp->next->val < temp->val){
                temp->next= temp->next->next;
            }
            else temp=temp->next;
        }
        return reverseList(head);
    }
};
