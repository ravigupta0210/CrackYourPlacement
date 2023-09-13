// Swap Nodes in Pairs


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy;
        while(head && head->next){
            ListNode* first = head, *second = head->next;
            
            prev->next = second;
            first->next = second->next;
            second->next = first;

            prev = first;
            head = first->next;
        }
        return dummy->next;
    }
};
