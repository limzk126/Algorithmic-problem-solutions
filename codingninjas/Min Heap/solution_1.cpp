void heapify(vector<int>& heap, int idx, int& heapSize) {
    int leftIdx = 2 * idx + 1;
    int rightIdx = 2 * idx + 2;
    int smallest = idx;
    if (leftIdx < heapSize && heap[leftIdx] < heap[idx]) {
        smallest = leftIdx;
    }
    if (rightIdx < heapSize && heap[rightIdx] < heap[smallest]) {
        smallest = rightIdx;
    }
 
    if (smallest != idx) {
        swap(heap[idx], heap[smallest]);
        heapify(heap, smallest, heapSize);
    }
}
    
void insert(vector<int>& heap, int newVal, int& heapSize) {
    ++heapSize;
    heap[heapSize - 1] = newVal;
 
    int i = heapSize - 1;
    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(heap[(i - 1) / 2], heap[i]);
        i = (i - 1) / 2; 
    }
}
 
int removeMin(vector<int>& heap, int& heapSize) {
    int res = heap[0];
    heap[0] = heap[heapSize - 1]; 
    --heapSize;
    heapify(heap, 0, heapSize);
    
    return res;
}
 
vector<int> minHeap(int n, vector<vector<int>>& q) {
    vector<int> res; 
    vector<int> heap(n + 1, 0); 
    int heapSize = 0;
    for (int i = 0; i < n; ++i) {
        if (q[i][0] == 0) { 
            insert(heap, q[i][1], heapSize);
        } else {
            int mini = removeMin(heap, heapSize);  
            res.push_back(mini);
        }       
    }
 
    return res;
}
