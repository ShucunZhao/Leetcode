class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param numbers int整型vector 
     * @return int整型
     */
    int duplicate(vector<int>& numbers) {
        // write code here
        /*    
             0 1 2 3 4 5 6
            [2,3,1,0,2,5,3]
        */
        unordered_set<int> numSet;
        for(int i : numbers){
            if(numSet.count(i)==0){
                numSet.insert(i);
            }
            else{
                return i;
            }
        }
        return -1;
    }
};