class Solution {
public:
    // string strSet = "()";
    string path;
    // stack<char> st;
    vector<string> ans;
    void backtracking(int numL, int numR, int n){
        if(path.size()==2*n){
            // cout<<"path:"<<path<<endl;
            // string tmp(path);
            // int i = tmp.size()-1;
            // while(i>=0){
            // // while(!st.empty()){
            // // if(st.top()=='('){
            //     if(tmp[i]=='('){
            //         tmp.push_back(')');
            //         i--;
            //         // st.pop();
            //     }
            //     else{
            //         tmp.push_back('(');
            //         tmp.push_back(')');
            //         i-=2;
            //     }       
            // }
            ans.push_back(path);
            return;
        }
        if(numL<n){
            path.push_back('(');
            numL++;
            backtracking(numL, numR, n);
            path.pop_back();
            numL--;
        }
        if(numR<numL){
            path.push_back(')');
            numR++;
            backtracking(numL, numR, n);
            path.pop_back();
            numR--;
        }
        // for(int i=start;i<strSet.size();i++){
        //     // if(path[0]==')'){
        //     //     break;
        //     // }
        //     // if(i>0&&path[i]==')')
        //     path.push_back(strSet[i]);
        //     backtracking(i, n);
        //     path.pop_back();
        // }
        return;
    }
    vector<string> generateParenthesis(int n) {
        backtracking(0, 0, n);
        // for(string s : ans){
        //     cout<<s<<",";
        // }
        // cout<<endl;
        return ans;
        /*
             [(()),()()]
             n==2:
                ( 
            ((      ()

        */
    }
};