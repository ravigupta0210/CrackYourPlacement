//  Remove Duplicates from Sorted List


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode* temp=head;
        while(temp!=NULL){
            if(temp->next!=NULL && temp->val == temp->next->val){
                temp->next= temp->next->next;
            }
            else
            temp= temp->next;
        }
        return head;
    }
};
