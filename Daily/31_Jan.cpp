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
