class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> res;
        // int i = 0;
        // while(i)
        // if(expression.size()==1){
        //     res.push_back(expression[0]-'0');
        //     return res;
        // }
        for(int i=0;i<expression.size();i++){
            char c = expression[i];
            if(c=='-'||c=='+'||c=='*'){
                // cout<<expression.substr(0,i)<<endl;
                // cout<<expression.substr(i+1)<<endl;
                vector<int> left = diffWaysToCompute(expression.substr(0,i));
                vector<int> right = diffWaysToCompute(expression.substr(i+1));
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
            res.push_back(stoi(expression));
        }
        return res;
    }
};