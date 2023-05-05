class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        /*
                         l
            name = "ssaaeed", typed = "ssaaedd"
                                              r
                       l
            name = "alex", typed = "aaleelx"   
                                         r
            if(name[l]==typed[r]){
                l++,r++
            }
            else{
                r++
            }
        */
        int l = 0, r = 0;
        for(l,r;l<name.size()&&r<typed.size();){
            if(name[l]==typed[r]){
                l++;
                r++;
            }
            else{
                if(r>0&&typed[r]==typed[r-1]){
                    r++;
                }
                else{
                    return false;
                }
            }
        }
        //cout<<l<<endl;
        if(l!=name.size()) return false;
        while(r<typed.size()&&typed[r]==typed[r-1]){
            r++;
        }
        //cout<<l<<","<<r<<endl;
        return r==typed.size();
    }
};