class Solution {
public:
    int longestValidParentheses(string s) {
        /*
         
            st:-1， the inialization state of stack is a sentinel -1 for the case when the first char is ')'. 
            ans: 2    
              l
             "()(()"
              01234
               l  
            ")()())"
             012345
            "((()))"
        */
        stack<int> st;//Stack to save index of char.
        st.push(-1);
        int ans = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]==')'){
                st.pop();//1,
                if(!st.empty()){
                    ans = max(ans, i-st.top());
                }
                else{
                    st.push(i);
                }
            }
            else{
                st.push(i);//1,
            }
        }
        return ans;
    }
};