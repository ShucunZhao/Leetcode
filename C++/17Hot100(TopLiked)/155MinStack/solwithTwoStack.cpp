class MinStack {
public: 
    /*
        st:    -2  0 -3 
        minSt: -2 -2 -3
    */
    stack<int> curSt, minSt;
    MinStack() {
        
    }
    
    void push(int val) {
        curSt.push(val);
        if(minSt.empty()){
            minSt.push(val);
            return;
        }
        if(val<minSt.top()){
            minSt.push(val);
        }
        else{
            minSt.push(minSt.top());
        }
        return;
    }
    
    void pop() {
        curSt.pop();
        minSt.pop();
    }
    
    int top() {
        return curSt.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */