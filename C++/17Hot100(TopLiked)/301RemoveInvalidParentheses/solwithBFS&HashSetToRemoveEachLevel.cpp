class Solution {
public:
    bool isValid(string & s){
        int cntR = 0;
        for(int i=0;i<s.size();i++){
            /*   i
                "()())()"
            */
            if(s[i]=='(') cntR++;
            else if(s[i]==')'){
                if(cntR==0) return false;
                cntR--;
            }
        }
        // cout<<"cntR:"<<cntR<<endl;
        return cntR==0;
    }
    vector<string> removeInvalidParentheses(string s) {
        if(isValid(s)) return {s};
        vector<string> ans;
        unordered_set<string> mset;
        queue<string> Q;
        Q.push(s);
        int size;
        while(!Q.empty()){
            size = Q.size();
            bool found = false;
            while(size--){
                string str = Q.front();
                Q.pop();
                for(int i=0;i<str.size();i++){
                    if(str[i]!='('&&str[i]!=')'){
                        continue;
                    }
                    string newS = str.substr(0,i)+str.substr(i+1);
                    // cout<<"newS:"<<newS<<endl;
                    if(mset.count(newS)){
                        continue;
                    }
                    if(isValid(newS)){
                        found = true;
                        ans.push_back(newS);
                    }
                    mset.insert(newS);
                    Q.push(newS);
                }
            }
            if(found){
                break;
            }
        }
        if(ans.empty()) return {""};
        return ans;
    }
};