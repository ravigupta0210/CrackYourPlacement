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
