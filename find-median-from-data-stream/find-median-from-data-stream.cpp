class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    MedianFinder() {
        
       while(!maxHeap.empty())
           maxHeap.pop();
    
       while(!minHeap.empty())
           minHeap.pop();
    }
    
    void addNum(int num) {
       if(maxHeap.empty()) {
           maxHeap.push(num);
           return;
       }
       
        if(maxHeap.top() > num)
            maxHeap.push(num);
        else
            minHeap.push(num);
        
        if(minHeap.size() > maxHeap.size()) {
            int temp = minHeap.top();
            minHeap.pop();
            maxHeap.push(temp);
        }
        if(maxHeap.size() - minHeap.size() >= 2) {
            int temp = maxHeap.top();
            maxHeap.pop();
            minHeap.push(temp);
        }
    }
    
    double findMedian() {
        if(maxHeap.size() == minHeap.size()) {
            return maxHeap.top() / 2.0 + minHeap.top() / 2.0;
        }
        else
            return maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */