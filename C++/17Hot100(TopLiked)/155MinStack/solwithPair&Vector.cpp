class MinStack {
private:
    vector<pair<int, int> > vec; 
public:
    MinStack() {
       
    }
    
    void push(int val) {
        if(vec.empty()){
            vec.push_back({val, val});
        }
        else{
            int curMin = vec.back().second;
            vec.push_back({val, min(val, curMin)});
        }
    }
    
    void pop() {
        if(!vec.empty()){
            vec.pop_back();
        }
    }
    
    int top() {
        return vec.back().first;
    }
    
    int getMin() {
        return vec.back().second;
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