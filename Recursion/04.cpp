// Palindrome Linked List


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode*  temp=head;
        while(temp){
            st.push(temp->val);
            temp=temp->next;
        }
        temp= head;
        bool res= false;
        while(temp){
            if(temp->val == st.top()){
                st.pop();
                temp=temp->next;
                res=true;
            }
            else return false;
        }
        return res;
    }
};
