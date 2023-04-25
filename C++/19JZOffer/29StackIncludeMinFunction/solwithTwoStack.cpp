class Solution {
private:
    stack<int> st;
    stack<int> minSt;
public:
    void push(int value) {      
        st.push(value);
        if(minSt.empty()){
            minSt.push(value);
        }
        else{
            if(minSt.top()<value){
                minSt.push(minSt.top());
            }
            else{
                minSt.push(value);
            }
        }
    }
    void pop() {
        st.pop();
        minSt.pop();
    }
    int top() {
        return st.top();
    }
    int min() {
        return minSt.top();
    }
};