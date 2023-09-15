// Reorder List



class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == NULL) return ;

        ListNode* temp = head, *half = head, *prev = NULL;

        while(temp->next && temp->next->next){
            temp = temp->next->next;
            half = half->next;
        }
        
        if(temp->next) half = half->next;

        while(half){
            temp = half->next;
            half->next = prev;
            prev = half;
            half = temp;
        }
        half = prev;

        while(half && head){
            temp =  head->next;
            prev = half->next;

            head->next = half;
            half->next = temp;

            head = temp;
            half = prev;
        }

        if(head && head->next) head->next->next =NULL;
        
    }
};
