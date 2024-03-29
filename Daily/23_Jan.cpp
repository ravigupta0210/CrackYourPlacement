// Rotate List

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        int len = solve(head);
        k=k%len;
        ListNode* slow = head;
        ListNode* fast = head;
        while(k--)
        fast=fast->next;
        if(fast==NULL) return head;
        while(fast->next){
            fast=fast->next;
            slow=slow->next;
        }
        fast->next=head;
        head=slow->next;
        slow->next=NULL;
        return head;
    }
};


// Copy List with Random Pointer

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
unordered_map<Node*,Node*> mp;
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        if(mp.count(head)) return mp[head];
        Node* newNode = new Node(head->val);
        mp[head] = newNode;
        newNode->next = copyRandomList(head->next);
        newNode->random = copyRandomList(head->random);
        return newNode;
    }
};


// 3Sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        int target=0;
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        set<vector<int>> temp;
        for(int i=0;i<n;i++){
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum == target){
                    temp.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }
                else if(sum < target) j++;
                else k--;
            }
        }
        for(auto i:temp)
        ans.push_back(i);
        return ans;
    }
};


// Trapping Rain Water

class Solution {
public:
    int trap(vector<int>& height) {
        int low=0,high=height.size()-1,leftMax=INT_MIN,rightMax=INT_MIN,ans=0;
        while(low<high){
            leftMax=max(leftMax,height[low]);
            rightMax=max(rightMax,height[high]);
            ans+=(leftMax<rightMax)?leftMax-height[low++]:rightMax-height[high--];
        }
        return ans;
    }
};


// Remove Duplicates from Sorted Array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        for(int j=1;j<nums.size();j++){
            if(nums[i]!=nums[j])
            i++;
            nums[i]=nums[j];
        }
        return i+1;
    }
};


// Max Consecutive Ones

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int n = nums.size();
    int cnt = 0;
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        if(nums[i] == 1){
            cnt++;
        }
       else{
         maxi = max(maxi, cnt);
         cnt = 0;
       }
    }
     maxi = max(maxi, cnt);
    if(maxi > n) return -1;

    return maxi;
    }
};
