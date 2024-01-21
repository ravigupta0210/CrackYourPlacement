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


// Palindrome Linked List

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
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode* temp=head;
        while(temp){
            st.push(temp->val);
            temp=temp->next;
        }
        temp=head;
        bool res=false;
        while(temp){
            if(temp->val == st.top()){
                res=true;
                temp=temp->next;
                st.pop();
            }
            else return false;
        }
        return res;
    }
};


// Linked List Cycle II


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
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=NULL)
        {
            fast=fast->next;
            if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
            }
            
            if(fast==slow){
                break;
            }

        }
        if(fast==NULL) return NULL;
        slow=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};


// Flattening a Linked List


//{ Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}

// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */

Node* merge(Node* head1,Node* head2){
    Node* ans=new Node(0);
    Node* temp=ans;
    while(head1 && head2){
        if(head1->data < head2->data){
            temp->bottom=head1;
            temp=temp->bottom;
            head1=head1->bottom;
        }
        else{
            temp->bottom=head2;
            temp=temp->bottom;
            head2=head2->bottom;
        }
    }
    if(head1)
    temp->bottom=head1;
    else temp->bottom=head2;
    return ans->bottom;
}    

Node *flatten(Node *root)
{
   if(root==NULL || root->next==NULL) return root;
   root->next=flatten(root->next);
   root=merge(root,root->next);
   return root;
}


