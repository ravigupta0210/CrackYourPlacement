// Reverse Linked List


class Solution {
public:
ListNode* solve(ListNode* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    ListNode* chotaHead = solve(head->next);
    head->next->next = head;
    head->next = NULL;
    return chotaHead;
}
    ListNode* reverseList(ListNode* head) {
        return solve(head);
    }
};
