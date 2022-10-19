class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(!st.empty()&&s[i]==st.top()){
                st.pop();
                s.erase(i-1, 2);
                i -= 2; 
            }
            else{
                st.push(s[i]);
            }
        }
        return s;
    }
};