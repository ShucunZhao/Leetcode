class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param array int整型vector 
     * @return int整型vector
     */
    vector<int> reOrderArray(vector<int>& array) {
        // write code here
        
        /*
        
            [2,4,6,5,7]
        index: 0
                   x
                   j
         i:  0 1 2 3 4     
            [2,2,4,6,7]
            
        */
        int oddI = 0;
        for(int i=0;i<array.size();i++){
            if(array[i]%2==1){
                int tmp = array[i];
                for(int j=i;j>oddI;j--){
                    array[j] = array[j-1];
                }
                array[oddI++] = tmp;
            }
        }

        return array;
    }
};