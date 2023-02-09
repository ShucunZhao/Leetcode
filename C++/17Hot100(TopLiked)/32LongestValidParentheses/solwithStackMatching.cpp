class Solution {
public:
    int longestValidParentheses(string s) {
        /*
            i:    0 1 2 3 4  
            s:    ( ) ( ( )
            [2,
            cnt:2 
            ans:2 
        */
        stack<int> st;
        st.push(-1);
        int ans = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else{
                    ans = max(ans, i-st.top());
                }
            }
        }
        return ans;
    }
};