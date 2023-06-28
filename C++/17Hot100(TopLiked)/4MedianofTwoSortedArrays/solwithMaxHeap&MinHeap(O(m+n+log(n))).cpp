class Solution {
public:
    priority_queue<int, vector<int>, greater<int> > maxHeap;//Smallest-top to save the larger elements.
    priority_queue<int, vector<int>, less<int> > minHeap;//Largest-top to save the smaller elements.
    void putInHeap(int num){
        if(minHeap.size()==0&&maxHeap.size()==0){
            minHeap.push(num);
            return;
        }
        if(minHeap.size()>=maxHeap.size()){
            if(minHeap.top()>num){
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(num);
            }
            else{
                maxHeap.push(num);
            }
        }
        else{//minHeap.size()<maxHeap.size():
            if(maxHeap.top()<num){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(num);
            }
            else{
                minHeap.push(num);
            }
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /*
             
            nums1 = [1,3], nums2 = [2]

            minHeap(Big-top):
                  2, 1  

            maxHeap(Small-top):
                  3  
        */   
        
        int l = 0, r = 0;
        for(l,r;l<nums1.size()&&r<nums2.size();){
            if(nums1[l]<nums2[r]){
                putInHeap(nums1[l]);
                l++;
            }
            else{   
                putInHeap(nums2[r]);
                r++;
            }
        }
        while(l<nums1.size()){
            putInHeap(nums1[l++]);
        }
        while(r<nums2.size()){
            putInHeap(nums2[r++]);
        }
        /*
        for(int i : nums1){
            minHeap.push(i);
        }
        */
        /*
        cout<<"minHeap:";
        while(!minHeap.empty()){
            cout<<minHeap.top()<<",";    
            minHeap.pop();     
        }
        cout<<endl;
        cout<<"maxHeap:";
        while(!maxHeap.empty()){
            cout<<maxHeap.top()<<",";    
            maxHeap.pop();     
        }
        cout<<endl;
        */
        if(minHeap.size()<maxHeap.size()){
            return maxHeap.top();
        }
        else if(maxHeap.size()<minHeap.size()){
            return minHeap.top();
        }
        // cout<<"min:"<<minHeap.top()<<endl;
        // cout<<"max:"<<maxHeap.top()<<endl;
        return ((double)minHeap.top()+(double)maxHeap.top())/2;
        return 0;
    }
};