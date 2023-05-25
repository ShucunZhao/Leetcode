class Solution {
public:
    string reverseStr(string s, int k) {
        /*
                 i     j 
            s = "abcdefg"X, k = 3
        */
        if(k>=s.size()){
            reverse(s.begin(), s.end());
            return s;
        } 
        for(int i=0;i<s.size();){
            int j = i+2*k-1;
            if(j<s.size()){
                reverse(s.begin()+i,s.begin()+i+k);
                i+=(2*k);
            }
            else{
                if(i<=s.size()-k){
                    reverse(s.begin()+i,s.begin()+i+k);
                    i+=(2*k);
                }
                else{
                    reverse(s.begin()+i, s.end());
                    i+=(2*k);
                }
            }
        }
        return s;
    }
};