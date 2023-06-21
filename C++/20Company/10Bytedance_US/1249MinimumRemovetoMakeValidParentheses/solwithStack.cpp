class Solution {
public:
    string minRemoveToMakeValid(string s) {
        /* 
                   i
            s   = "lee(t(c)o)de)"
            st: base|[ )
        */
        stack<int> st;
        for(int i=0;i<s.size();){
            if(s[i]=='('){
                st.push(i);
                i++;
            }
            else if(s[i]==')'){
                if(st.empty()){
                    s.erase(i,1);
                }
                else{
                    st.pop();
                    i++;
                }
            }
            else{
                i++;
            }
        }
        while(!st.empty()){
            s.erase(st.top(), 1);
            st.pop();
        }
        return s;
    }
};