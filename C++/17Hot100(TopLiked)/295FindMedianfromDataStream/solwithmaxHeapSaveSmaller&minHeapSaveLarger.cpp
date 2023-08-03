class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int> > minHeap;//Store larger num
    priority_queue<int, vector<int>, less<int> > maxHeap; //Store smaller num
    // int size = 0;
    /*  
        (save larger) min: 1
        (save smaller)max: 
        1   2   3

    */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // size++;
        if(minHeap.empty()&&maxHeap.empty()){
            minHeap.push(num);
        }
        else if(maxHeap.empty()){
            if(num>minHeap.top()){
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(num);
            }
            else{
                maxHeap.push(num);
            }
        }
        else{
            if(minHeap.size()<maxHeap.size()){
                if(num<maxHeap.top()){
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                    maxHeap.push(num);
                }
                else{
                    minHeap.push(num);                   
                }
            }
            else{
                if(num>minHeap.top()){
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                    minHeap.push(num);
                }
                else{
                    maxHeap.push(num);
                }
            }
        }
    }
    
    double findMedian() {
        // if(size)
        if(minHeap.size()==maxHeap.size()){
            return (double)(minHeap.top()+maxHeap.top())/2.0;
        }
        else if(minHeap.size()>maxHeap.size()){
            return minHeap.top();
        }
        return maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */