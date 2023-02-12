class Solution {
public:
    void myReverse(string & s, int l, int r){
        while(l<=r){
            swap(s[l], s[r]);
            l++;
            r--;
        }
    }
    string reverseWords(string s) {
        /*
                        l
            Input: s = "the sky is blue"
                                      r
            step1:      eulb si yks eht   (reverse whole) 
            ------------------------------------------------------
                                        l
            step2:      "blue is sky the  is sky the"  (remove redundant space)
                                                   r                                    
            ------     
                         i                                                                     
            step3:       eulb si yks eht   (reverse each words)
                             j
            Output: "blue is sky the"
        */
        myReverse(s, 0, s.size()-1);
        int l=0,r=0;
        for(l,r;r<s.size();r++){
            if(s[r]!=' '){
                if(l!=0){
                    s[l++] = ' ';
                }
                while(s[r]!=' '&&r<s.size()){
                    s[l++] = s[r++];
                }
            }
        }
        s.resize(l);
        for(int i=0,j=0;j<=s.size();j++){
            if(j==s.size()){
                myReverse(s, i, j-1);
                // cout<<"i:"<<i<<",j:"<<j<<endl;
            }
            else if(s[j]==' '){
                // cout<<"i:"<<i<<",j:"<<j<<endl;
                myReverse(s, i, j-1);
                i=j+1;
            }
        }
        // for(char c : s){
        //     cout<<c;
        // }
        // cout<<endl;
        return s;
        // return "";
    }   
};