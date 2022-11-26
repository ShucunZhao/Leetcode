class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return (getStr(s)==getStr(t));
    }
    string getStr(string & input){
        int l=0;
        for(int f=0;f<input.size();f++){
            if(input[f]!='#'){
                input[l]=input[f];
                l++;
            }
            else{
                if(l!=0){//When '#' appear at the first pos we don't need to minus the l.
                    l--;
                }
            }
        }
        string ans = input.substr(0,l);
        return ans;
    }
};