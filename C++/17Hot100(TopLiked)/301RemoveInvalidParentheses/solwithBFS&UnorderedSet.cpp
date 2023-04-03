class Solution {
public:
    unordered_set<string> set;
    bool isValid(string & s){
        int cntR = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') cntR--;
            else if(s[i]==')'){
                if(cntR==0){
                    return 0;
                }
                cntR++;
            }
        }
        return cntR==0;
    }
    vector<string> removeInvalidParentheses(string s) {
        /*
            We delete one char each time to do the bfs to find the ans:
            s = "((()((s((((()"
            newStr:  "(())()" 
            ans: ["()s()","()(s)","(()s)"]
        */
        if(isValid(s)) return {s};
        vector<string> ans;
        queue<string> Q;
        Q.push(s);//"((()((s((((()",
        int size;
        bool found = 0;
        while(!Q.empty()&&!found){
            size = Q.size();//1,
            while(size--){
                //Q:")"
                string cur = Q.front();//"((()((s((((()"
                Q.pop();
                if(cur.size()==1){
                    return {""};
                }
                for(int i=0;i<cur.size();i++){
                    if(cur[i]!='('&&cur[i]!=')') continue;
                    string newStr = cur.substr(0, i) + cur.substr(i+1);//""
                    //cout<<"newStr:"<<newStr<<endl;
                    if(set.count(newStr)!=0) continue;
                    if(isValid(newStr)){
                        found = 1;
                        //cout<<"newStr:"<<newStr<<endl;
                        //cout<<"sizeOfQueue:"<<Q.size()<<endl;
                        ans.push_back(newStr);
                    }
                    set.insert(newStr);
                    Q.push(newStr);//"(",")"
                }
            }
        }
        return ans;
    }
};