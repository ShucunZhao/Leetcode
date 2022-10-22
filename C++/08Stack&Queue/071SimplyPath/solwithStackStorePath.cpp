class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string str;
        stringstream ss(path);
        while(getline(ss, str, '/')){
            if(str==".."){//KeyPoint: You must enter this if function when str is equal to ".." because we will add nothing 
                          //to stack if it is already empty and pop the top if there are something inside of it.
                if(!st.empty()){
                    st.pop();
                }
            }
            else if(str!="."&&str!=""){
                st.push(str);
            }
        }
        string ans;
        while(!st.empty()){
            ans = "/"+st.top()+ans;
            st.pop();
        }
        return ans.empty()?"/":ans;
    }
};