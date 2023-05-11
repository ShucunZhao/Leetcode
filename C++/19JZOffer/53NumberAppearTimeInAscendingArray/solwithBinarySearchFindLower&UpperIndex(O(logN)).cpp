class Solution {
public:
    int findIndex(vector<int> data, int k, bool low){
        int l=0, r=data.size();
        while(l<=r){
            int m = l+(r-l)/2;
            if(data[m]>k){
                r = m-1;
            }
            else if(data[m]<k){
                l = m+1;
            }
            else{
                if(low){
                    if(m>0&&data[m-1]==k){
                        r = m-1;
                    }
                    else{
                        return m;
                    }
                }
                else{
                    if(m<data.size()-1&&data[m+1]==k){
                        l = m+1;
                    }
                    else{
                        return m;
                    }
                }

            }
        }
        return -1;
    }
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.size()==0) return 0;
        int lower = findIndex(data, k, 1);
        if(lower==-1) return 0;
        int upper = findIndex(data, k, 0);
        return upper-lower+1;
    }
};