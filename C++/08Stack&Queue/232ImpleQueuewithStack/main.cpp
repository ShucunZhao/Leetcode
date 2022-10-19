/*
 * Sol: You need to use two stack to represent the In-queue and Out-queue operation
 */
class MyQueue {
public:
    stack<int> in;
    stack<int> out;
    MyQueue() {
        
    }
    
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        if(out.empty()){
            while(!in.empty()){
                out.push(in.top());
                in.pop();
            }
        }
        int rst = out.top();
        out.pop();
        return rst;
    }
    
    int peek() {
        int rst = this->pop();
        out.push(rst);
        return rst;
    }
    
    bool empty() {
        return in.empty()&&out.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */