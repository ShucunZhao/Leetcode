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
        vector<int> odd, even;
        for(int i=0;i<array.size();i++){
            if(array[i]%2==1){
                odd.push_back(array[i]);
            }
            else{
                even.push_back(array[i]);
            }
        }
        int index = 0;
        for(int i=0;i<odd.size();i++){
            array[index++] = odd[i];
        }
        for(int i=0;i<even.size();i++){
            array[index++] = even[i];
        }
        return array;
    }
};