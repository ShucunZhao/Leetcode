class Solution {
public:
    int compareVersion(string version1, string version2) {
        /*
                        l    
            version1 = "1.01", 
                        r
                        l
            version2 = "1.001"
                        r
 -----------------------------------------------
                          l
            version1 = "1.0.0"  
                           r
                        l            
            version2 = "1.0.0"       
                        r                
        */
        int oneL = 0, oneR = 0, twoL = 0, twoR = 0;
        int size1 = version1.size(), size2 = version2.size();
        while(oneR<size1&&twoR<size2){
            while(oneR<size1&&version1[oneR]!='.') oneR++;
            string num1 = version1.substr(oneL, oneR-oneL);
            // cout<<"version1:"<<version1<<endl;
            // cout<<"oneL:"<<oneL<<", oneR:"<<oneR<<endl;
            // cout<<"num1:"<<num1<<endl;
            oneR++;
            oneL = oneR;
            while(twoR<size2&&version2[twoR]!='.') twoR++;
            string num2 = version2.substr(twoL, twoR-twoL);
            // cout<<"twoL:"<<twoL<<", twoR:"<<twoR<<endl;    
            twoR++;
            twoL = twoR;
            // cout<<"num2:"<<num2<<endl; 
            if(stoi(num1)>stoi(num2)) return 1;
            else if(stoi(num1)<stoi(num2)) return -1;
        }
        while(oneR<size1){
            while(oneR<size1&&version1[oneR]!='.') oneR++;
            if(stoi(version1.substr(oneL, oneR-oneL))>0) return 1;
            oneR++;
            oneL = oneR;
        }
        while(twoR<size2){
            while(twoR<size2&&version2[twoR]!='.') twoR++;
            if(stoi(version2.substr(twoL, twoR-twoL))>0) return -1;
            twoR++;
            twoL = twoR;
        }        
        return 0;
    }
};