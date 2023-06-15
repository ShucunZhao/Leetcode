class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
            /*
                matrix = [[3,7,8],  3
                          [9,11,13],  9
                          [15,16,17]]   15

                matrix = [[1,10,4,2],
                          [9,3,8,7],
                          [15,16,17,12]]          
            */
        bool jump = false;
        vector<int> ans;
        for(int i=0;i<matrix.size();i++){
            auto min = min_element(matrix[i].begin(), matrix[i].end());
            int minVal = *min;
            int indexCol = distance(matrix[i].begin(), min);
            int indexRow = i;
            //cout<<"index:"<<index<<",minVal:"<<minVal<<endl;
            for(int j=0;j<matrix.size();j++){
                if(j==indexRow){
                    continue;
                }
                if(matrix[j][indexCol]>minVal){
                    jump = true;
                    break;
                }
            }
            if(!jump){
                ans.push_back(minVal);
            }
            jump = false;
        }
        return ans;
    }
};