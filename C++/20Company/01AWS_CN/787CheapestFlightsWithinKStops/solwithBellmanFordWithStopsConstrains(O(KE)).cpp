class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        /*
             i:     0     1     2       3
            dist:   0    100    200     700
            tmp:    0    100    200     700
        */
        vector<long long> tmp(n, INT_MAX);
        tmp[src] = 0;
        vector<long long> dist;
        //bool check = false;
        for(int x=0;x<=k;x++){//1
            dist.assign(tmp.begin(), tmp.end());
            for(int i=0;i<flights.size();i++){
                int cur = flights[i][0];
                if(dist[cur]==INT_MAX){
                    continue;
                }
                int end = flights[i][1];
                if(tmp[end]>dist[cur]+flights[i][2]){//KeyPoint! Use the unpdated tmp to compare with un-updated dist array to update tmp.
                    tmp[end] = dist[cur]+flights[i][2];
                    //check = true;
                }
            }
            /*
            if(!check){
                break;
            }
            */
        }
        /*
        for(int i=0;i<n;i++){
            cout<<tmp[i]<<endl;
        }
        */
        return tmp[dst]==INT_MAX?-1:tmp[dst];
    }
};