class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> st;
        char * flag;
        long a,b;
        for(string s : tokens){
            long i = strtol(s.c_str(), &flag, 10);
            if(*flag==0){
                st.push(i);
            }
            else if(s=="+"){
                b = st.top();
                st.pop();
                a = st.top();
                st.pop();
                st.push(a+b); 
            }
            else if(s=="-"){
                b = st.top();
                st.pop();
                a = st.top();
                st.pop();
                st.push(a-b); 
            } 
            else if(s=="*"){
                b = st.top();
                st.pop();
                a = st.top();
                st.pop();
                st.push(a*b); 
            }
            else{
                b = st.top();
                st.pop();
                a = st.top();
                st.pop();
                st.push(a/b); 
            }                             
        }
        return st.top();
    }
};