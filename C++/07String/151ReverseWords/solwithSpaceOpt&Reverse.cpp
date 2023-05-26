class Solution {
public:
    string reverseWords(string s) {
        /*
            "  hello    world  "
            Step1:
                  l
                     r    
            "hello    world  " 
            Step2:
            "hello world  "
            Step3:
                         l
                         r
            "hello world  "  
            Step4:
            reverse each word and reverse the whole sentence to get the answer.
            l    
                 r
            hello world
        */
        //Step1: move the head space:
        int i = 0;
        while(i<s.size()&&s[i]==' ') i++;
        s.erase(0, i);
        //Step2: move the gap space:
        /*
                     l
                        r   
            "F R I E N     D      S      "
        */
        for(int l=i,r=i;r<s.size();){
            while(r<s.size()&&s[r]!=' ') r++;
            r++;
            l=r;
            while(r<s.size()&&s[r]==' ') r++;
            if(r!=l){
                // cout<<"l:"<<l<<",r:"<<r<<endl;
                // if(r==11){
                //     cout<<"s[l-2]:"<<s[l-2]<<endl;
                //     cout<<"s[r]:"<<s[r]<<",s[r+1]:"<<s[r+1]<<endl;
                // }
                s.erase(l, r-l);
            }

            //cout<<s<<endl;
            r=l;//KeyPoint here: You must return the r to l because you have cut the space rather than let l pointer to r!
        }
        //return s;
        //Step3: move the tail space:
        if(s[s.size()-1]==' ') s.erase(s.size()-1, 1);
        //Step4.1: reverse each word
        for(int l=0,r=0;r<s.size();){
            while(r<s.size()&&s[r]!=' ') r++;
            reverse(s.begin()+l, s.begin()+r);
            r++;
            l=r;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};