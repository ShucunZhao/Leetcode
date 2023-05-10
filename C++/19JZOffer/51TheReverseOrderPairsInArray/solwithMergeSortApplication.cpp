class Solution {
public:
    int cnt = 0;
    void mergeSort(vector<int> & data, int l, int r){
        if(l>=r) return;
        int m = l+(r-l)/2;
        mergeSort(data, l, m);
        mergeSort(data, m+1, r);
        vector<int> tmp;
        int i=l, j = m+1;
        while(i<=m&&j<=r){
            if(data[i]>data[j]){
                cnt+=(m-i+1);
                cnt%=1000000007;//Do the mod operation here is prevent to cnt overflow!
                tmp.push_back(data[j++]);
            }
            else{
                tmp.push_back(data[i++]);
            }
        }
        while(i<=m){
            tmp.push_back(data[i++]);
        }
        while(j<=r){
            tmp.push_back(data[j++]);
        }
        for(int x=l,p=0;x<=r;x++,p++){
            data[x] = tmp[p];
        }
        return;
    }
    int InversePairs(vector<int> data) {
        mergeSort(data, 0, data.size()-1);
        /*
        for(int i : data){
            cout<<i<<endl;
        }
        */
        return cnt;
        //return cnt%1000000007;//If do the mod when return answer it would be overflow if the size of cnt is very large.
    }
};