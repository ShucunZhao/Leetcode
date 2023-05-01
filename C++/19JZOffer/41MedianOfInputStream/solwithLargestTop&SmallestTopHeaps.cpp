class Solution {
public:
    priority_queue<int, vector<int>, less<int> > maxHeap;//Keep the smaller values in the largest-top heap
    priority_queue<int, vector<int>, greater<int> > minHeap;//Keep the bigger values in the smallest-top heap
    /*
        nums:  [5,2,3,4,1,6,7,0,8]
        maxHeap:2,3
        minHeap:5
        median:5,3.5,3  
    */
    void Insert(int num) {
        if(minHeap.size()>=maxHeap.size()){
            if(!minHeap.empty()&&num>minHeap.top()){
                int tmp = minHeap.top();
                minHeap.pop();
                minHeap.push(num);
                num = tmp;
            }
            maxHeap.push(num);
        }
        else{
            if(num<maxHeap.top()){
                int tmp = maxHeap.top();//5
                maxHeap.pop();//
                maxHeap.push(num);//2
                num = tmp;
            }
            minHeap.push(num);
        }
    }

    double GetMedian() { 
        if(minHeap.size()>maxHeap.size()){
            return (double)minHeap.top();
        }
        else if(minHeap.size()<maxHeap.size()){
            return (double)maxHeap.top();
        }
        return ((double)minHeap.top()+(double)maxHeap.top())/2;
    }

};