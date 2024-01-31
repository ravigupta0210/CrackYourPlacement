// Stack Implementation Using Array

// Stack class.
class Stack {
    
public:
    int capacity;
    vector<int> stack;
    int index=-1;
    Stack(int capacity) {
        this->capacity=capacity;
        stack.reserve(capacity);
    }

    void push(int num) {
        if(!isFull()){
            index++;
            stack[index]=num;
        }
        else return ;
    }

    int pop() {
        if(!isEmpty()){
            int ans = stack[index];
            index--;
            return ans;
        }
        else return -1;
    }
    
    int top() {
       if(!isEmpty()) return stack[index];
       else return -1;
    }
    
    int isEmpty() {
        if(index==-1) return 1;
        else return 0;
    }
    
    int isFull() {
        if(index+1==capacity) return 1;
        else return 0;
    }
    
};


// Implement a Queue

class Queue {
 
public:
int *arr;
int rear;
int qfront;
int size;
    Queue() {
        size=100001;
        arr = new int[size];
        qfront=0;
        rear=0;
    }


    bool isEmpty() {
        if(qfront==rear) return true;
        else return false;
    }

    void enqueue(int data) {
        if(rear==size){
            cout<<"Queue is Full"<<endl;
        }
        else{
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        if(qfront==rear) return -1;
        else{
            int ans=arr[qfront];
            arr[qfront]=-1;
            qfront++;
            if(rear==qfront){
                qfront=0;
                rear=0;
            }
            return ans;
        }
    }

    int front() {
        if(rear==qfront) return -1;
        else
        return arr[qfront];
    }
};


// Implement Stack using Queues


class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        int n=q.size();
        q.push(x);
        for(int i=0;i<n;i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int x=q.front();
        q.pop();
        return x;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */



// Valid Parentheses

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(ch=='(' || ch=='{' || ch=='[')
            st.push(ch);
            else if(st.size()>0 && st.top() == '(' && ch==')')
            st.pop();
            else if(st.size()>0 && st.top() == '[' && ch==']')
            st.pop();
            else if(st.size()>0 && st.top() == '{' && ch=='}')
            st.pop();
            else return false;
        }
        if(!st.empty()) return false;
        else return true;
    }
};


// Next Greater Element II

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i=2*n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums[i%n])
            st.pop();

            if(i<n){
                if(!st.empty())
                ans[i] = st.top();
            }
            st.push(nums[i%n]);
        }
        return ans;
    }
};
