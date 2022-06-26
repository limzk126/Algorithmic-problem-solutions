class MedianFinder {
public:
	priority_queue<double, vector<double>, lesser<double>> maxHeap;
	priority_queue<double, vector<double>, greater<double>> minHeap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
		maxHeap.push(num);
		minHeap.push(maxHeap.top());
		maxHeap.pop();

		if (maxHeap.size() < minHeap.size()) {
			maxHeap.push(minHeap.top());
			minHeap.pop();
		}
    }
    
    double findMedian() {
		if (maxHeap.size() > minHeap.size()) {
			return maxHeap.top();
		} else {
			return (maxHeap.top() + minHeap.top()) / 2;
		}
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
