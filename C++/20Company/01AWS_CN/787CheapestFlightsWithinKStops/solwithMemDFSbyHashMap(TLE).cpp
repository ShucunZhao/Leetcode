class Solution {
public:
    map<pair<int,int>, int> ms;
    int helper(vector<vector<int>>& flights, int src, int dst, int k) {
        /*
             src = 0, dst = 3, k = 1
             flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]]

            src = 0, dst = 2, k = 1
            flights = [[0,1,100],[1,2,100],[0,2,500]]
        */
        int minPrice = -1;
        if(k==-1){
            return minPrice;
        }
        /*
        if(ms[src][k]){
            return ms[src][k];
        }
        */
        if(ms.count({src,k})){
            return ms[{src,k}];
        }
        for(int i=0;i<flights.size();i++){
            if(flights[i][0]==src){
                if(flights[i][1]==dst){
                    if(minPrice==-1||minPrice>flights[i][2]){
                        minPrice = flights[i][2];
                        ms[{src,k}] = minPrice;
                        //ms[src][k] = minPrice;
                    }
                }
                else{
                    int cost = helper(flights,flights[i][1],dst,k-1);
                    if(cost!=-1){
                        cost+=flights[i][2];
                        if(minPrice==-1||minPrice>cost){
                            minPrice = cost;
                            ms[{src,k}] = minPrice;
                            //ms[src][k] = minPrice;
                        }
                    }
                }
            }
        }
        //ms[{src,dst}] = minPrice;
        return minPrice;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //vector<vector<int> > ms(n, vector<int>(n, 0));
        return helper(flights, src, dst, k);
    }
};