class Solution {
public:
    void reverseWord(string & str, int l, int r){
        //cout<<"l:"<<l<<","<<"r:"<<r<<endl;
        while(l<=r){
            swap(str[l], str[r]);
            l++;
            r--;
        }
        //cout<<str.substr(l, r-l+1)<<endl;
        return;
    }
    string ReverseSentence(string str) {
        /*
             str:  "nowcoder. a am I"
                    
                         l
                          r
             rev:   I ma a .redocwon
                    I am a nowcoder.
        */
        reverse(str.begin(), str.end());
        int l=0,r=0;
        while(r<str.size()){
            if(str[r]!=' '){
                r++;
            }
            else{
                reverseWord(str, l, r-1);
                r++;
                l=r;
            }
        }
        reverseWord(str, l, r-1);
        return str;
    }
};