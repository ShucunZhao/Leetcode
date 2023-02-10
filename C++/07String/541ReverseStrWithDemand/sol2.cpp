class Solution {
public:
    void myReverse(string & s, int l, int r){
        while(l<r){
            swap(s[l],s[r]);
            l++;
            r--;
        }
    }
    string reverseStr(string s, int k) {
        /*
                       l r 
                       i 
                 01234567   
            s = "bacdefgc", k = 3 
            
        */
        for(int i=0;i<s.size();i+=2*k){
            int r = i+k-1;
            if(r>s.size()-1) r = s.size()-1;
            myReverse(s, i, r);
        }
        return s;
    }
};