/*
 * Use Binary tree to cogitation to realize reverse polish notation
 */
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        for(string s : tokens){
            if(s=="+"||s=="-"||s=="*"||s=="/"){
                long long num1 = st.top();
                st.pop();
                long long num2 = st.top();
                st.pop();
                // cout<<*c<<endl;
                if(s=="+"){
                    st.push(num2+num1);
                }
                else if(s=="-"){
                    st.push(num2-num1);
                }
                else if(s=="*"){
                    st.push(num2*num1);
                }
                else{
                     st.push(num2/num1);
                }
            }
            else{
                st.push(stoll(s));
                //cout<<st.top();
            }
        }
        return st.top();
    }
};