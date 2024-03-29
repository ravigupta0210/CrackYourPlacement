// Given a linked list of 0s, 1s and 2s, sort it.


class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        int count0 = 0 , count1 =0 ,count2 =0;
        Node* temp=head;
        while(temp!=NULL){
            if(temp->data == 0) count0++;
            else if(temp->data == 1) count1++;
            else if(temp->data == 2) count2++;
            temp=temp->next;
        }
        temp = head;
        while(temp){
            if(count0){
                temp->data = 0;
                count0--;
            }
            else if(count1){
                temp->data = 1;
                count1--;
            }
            else if(count2){
                temp->data = 2;
                count2--;
            }
            temp=temp->next;
        }
        return head;
    }
};
