class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param array int整型vector 
     * @return int整型vector
     */
    vector<int> reOrderArrayTwo(vector<int>& array) {
        // write code here
        /*
               l
                 r
            [1,3,2,4]]
        */
        for(int l=0,r=0;r<array.size();){
            if((array[l]&1)==0){//KeyPoint here: The &(and) operation need to use the () to hold inside!
                while(r<array.size()&&(array[r]&1)==0){//KeyPoint here: The &(and) operation need to use the () to hold inside!
                    r++;
                }
                if(r==array.size()) continue;
                swap(array[l],array[r]);
            }
            l++;
            r++;
        }
        return array;
    }
};