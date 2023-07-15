class Solution {
public:
    bool isMatch(string s, string p) {
        /*
            The effect of mathc and star pointers:
                When the char x after * in p has multiple matching x in s, the match will pull the i 
                pointer back to the match+1 that can let the x in s to match x in p, if not match try 
                the second x in s then try the third x in s and so on...
                While the star pointer is used for pulling the j back to the star+1 position. 

            match: -1
            star:  -1         
                i
          S:  "adceb"       
                m
               
                  j
          P:  "*a*b"
                 s

            match: -1
            star:  -1         
                i
          S:  "aa"       
                m 
               
                j
          P:  "*"
               s

            match: -1
            star:  -1         
                    i
          S:  "abcdde"       
                  m
                 j
          P:  "a*d?"
                s               
        */
        int star = -1, match = -1;
        int i=0,j=0;
        while(i<s.size()){
            if(j<p.size()&&(s[i]==p[j]||p[j]=='?')){
                i++;
                j++;
            }
            else if(j<p.size()&&p[j]=='*'){
                star = j;
                j = star+1;
                match = i;
            }
            else if(star!=-1){
                match++;
                i = match;
                j = star+1;
            }
            else{
                return false;
            }
        }
        // if(i<s.size()) return false;
        while(j<p.size()&&p[j]=='*') j++;
        return j==p.size();
    }
};