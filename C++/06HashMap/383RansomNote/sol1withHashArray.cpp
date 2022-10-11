class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int ran = ransomNote.size();
        int mag = magazine.size();
        if(ran>mag){
            return 0;
        }
        int save[26] = {0};
        for(int i=0;i<ran;i++){
            save[ransomNote[i]-'a']--;
        }
        for(int j=0;j<mag;j++){
            save[magazine[j]-'a']++;
        }
        for(int k=0;k<26;k++){
            if(save[k]<0){
                return 0;
            }
        }  
        return 1;
    }
};