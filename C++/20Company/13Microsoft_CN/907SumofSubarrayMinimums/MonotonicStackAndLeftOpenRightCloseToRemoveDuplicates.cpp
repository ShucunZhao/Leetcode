class Solution {
public:
    /*
        Sol with find the intervals whose samllest element is current element when traversing the original array.
        For example:
            i:     0 1 2 3 
            arr = [3,1,2,4]
                 
         when i in pos 0: the intervals whose minimum is arr[0] is:    [3] - one case.
                                                        and the left posible index range is from[0,0] which is one case,
                                                        the right posible index range is from [0,0] which is one case,
                            so the value of all situations in here is: 3*1.
         when i in pos 1: the intervals whose minimum is arr[1] is:    [1],[3,1],[1,2],[1,2,4],[3,1,2],[3,1,2,4] - six cases.
                                                                       and the left posible index range is from[0,1] which is two cases,
                                                                       the right posible index range is from [0,4] which is four cases,
                                                                       so total is 2*4 = 6;
                            so the value of all situations in here is: 3*tatal = 3*6.
        and so on......

        So we can use the monotonic stack to find the first previous and next smaller element of current element, then find all cases.
     */
    int sumSubarrayMins(vector<int>& arr) {
        int mod = 1e9+7;
        arr.insert(arr.begin(), 0);
        arr.push_back(0);
        // cout<<"i:      ";
        // for(int i=0;i<arr.size();i++) cout<<i<<",";
        // cout<<endl;
        // cout<<"arr:    ";
        // for(int i : arr) cout<<i<<",";
        // cout<<endl;
        vector<int> preMin(arr.size());
        vector<int> nextMin(arr.size());
        for(int i=0;i<arr.size();i++){
            preMin[i] = i;
            nextMin[i] = i;
        }
        stack<int> st;//Monotonic stack for storing index of element.
        /*
            nextMin:   0  2 2 5 5 5  6 
            preMin:    0  1 2 3 4 5  6
                       0  1 2 3 4 5  6 
            arr   =   [-1,3,1,2,4,1,-1]
            [0, 2,5 
             -1 1 1 
        */
        for(int i=0;i<arr.size();i++){
            while(!st.empty()&&arr[st.top()]>arr[i]){
                nextMin[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        // cout<<"nextMin:";
        // for(int i=0;i<nextMin.size();i++){
        //     cout<<nextMin[i]<<",";
        // }
        cout<<endl;
        while(!st.empty()) st.pop();
        for(int j=arr.size()-1;j>=0;j--){
            //while(!st.empty()&&arr[st.top()]>arr[j]){KeyPoint here to remove the duplcates situation!!!
                                                    //We just not include the left duplicates and include the right duplicates to do this. 
            while(!st.empty()&&arr[st.top()]>=arr[j]){
                preMin[st.top()] = j;
                st.pop();
            }
            st.push(j);
        }     
        // cout<<"preMin: ";
        // for(int i=0;i<preMin.size();i++){
        //     cout<<preMin[i]<<",";
        // }
        // cout<<endl;
        /*
                i： 0 1 2 3
            nextMin:1,1,2,3,
            preMin: 0,1,1,2,
        */
        /*
            [-1,3,1,2,4,1,-1]
        */
        /*
        [3,];[3,1,];[3,1,2,];[3,1,2,4,];[3,1,2,4,1,]
        [1,];[1,2,];[1,2,4,];[1,2,4,1,]
        [2,];[2,4,];[2,4,1,]
        [4,];[4,1,]
        [1,]
        3, 
        */
        // unordered_set<int> mset;
        long long res = 0;
        for(int i=1;i<arr.size()-1;i++){
            // if(mset.count(arr[i])){
            //     continue;
            // }
            // mset.insert(arr[i]);
            // cout<<arr[i]<<": "<<(nextMin[i]-i)*(i-preMin[i])<<endl;
            res+=((long long)arr[i]*(long long)(nextMin[i]-i)*(long long)(i-preMin[i]))%mod;
        }
        // cout<<res%mod<<endl;
        return res%mod;   
        
        //return -1;
    }
};