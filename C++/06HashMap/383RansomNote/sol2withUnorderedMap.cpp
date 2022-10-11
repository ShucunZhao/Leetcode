class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int ran = ransomNote.size();
        int mag = magazine.size();
        if(ran>mag){
            return 0;
        }
        unordered_map<char, int> mmag, mran;
        for(int i=0;i<mag;i++){
            mmag[magazine[i]]++;
        }
        for(int j=0;j<ran;j++){
            mran[ransomNote[j]]++;
            if(mran[ransomNote[j]]>mmag[ransomNote[j]]){
                return 0;
            }
        }
        return 1;
    }
};