class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        //name =  "leelee"
        //typed = "lleeelee"
        int l=0, r=0;
        for(l,r;l<name.size()&&r<typed.size();){
            if(name[l]==typed[r]){
                l++;
                r++;
            }
            else{
                if(r==0) return 0;//EdgeCase1: if the first element is different return false directly.
                while(r<typed.size()&&typed[r]==typed[r-1]) r++;//EdgeCase2: When meet the unmatched case need to jump the contiguous 
                                                                //same elements, then judge if equal.
                if(name[l]==typed[r]){
                    l++;
                    r++;
                }
                else return 0;
            }
        }
        if(l!=name.size()) return 0;//EdgeCase3: if name set remains elements means the matching is false.
        while(r<typed.size()&&typed[r]==typed[r-1])  r++;
        if(r!=typed.size()) return 0;//EdgeCase4: if typed set remains elements there are two cases:
                                                //I.All remain elements are same then return ture.
                                               //II.After jumping all same elements if still reamins something which means matching false.
        return 1;
    }
};