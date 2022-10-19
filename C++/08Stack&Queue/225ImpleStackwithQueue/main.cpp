class MyStack {
public:
    queue<int> Q;
    MyStack() {
        
    }
    
    void push(int x) {
        Q.push(x);
    }
    
    int pop() {
        for(int i=0;i<Q.size()-1;i++){
            int mid = Q.front();
            Q.pop();
            Q.push(mid);
        }
        int rst = Q.front();
        Q.pop();
        return rst;
    }
    
    int top() {
        return Q.back();
    }
    
    bool empty() {
        return Q.empty();
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