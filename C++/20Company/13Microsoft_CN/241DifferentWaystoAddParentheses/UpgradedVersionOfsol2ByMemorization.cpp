class Solution {
public:
    map<pair<int,int>, vector<int> > ms;
    vector<int> helper(string & expression, int lp, int rp){
        if(ms.count({lp,rp})){
            return ms[{lp,rp}];
        }
        vector<int> res;
        for(int i=lp;i<=rp;i++){
            char c = expression[i];
            if(c=='-'||c=='+'||c=='*'){
                // cout<<expression.substr(0,i)<<endl;
                // cout<<expression.substr(i+1)<<endl;
                vector<int> left = helper(expression, lp, i-1);
                vector<int> right = helper(expression,i+1,rp);
                for(int l=0;l<left.size();l++){
                    for(int r=0;r<right.size();r++){
                        if(c=='-'){
                            res.push_back(left[l]-right[r]);
                        }
                        else if(c=='+'){
                            res.push_back(left[l]+right[r]);
                        }
                        else{
                            res.push_back(left[l]*right[r]);
                        }
                    }
                }
            }
        }
        if(res.empty()){
            res.push_back(stoi(expression.substr(lp,rp-lp+1)));
        }
        ms[{lp,rp}] = res;
        return res;
    }
    vector<int> diffWaysToCompute(string expression) {
        // int i = 0;
        // while(i)
        // if(expression.size()==1){
        //     res.push_back(expression[0]-'0');
        //     return res;
        // }
        return helper(expression, 0, expression.size()-1);
    }
};