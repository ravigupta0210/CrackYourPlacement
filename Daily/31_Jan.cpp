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
