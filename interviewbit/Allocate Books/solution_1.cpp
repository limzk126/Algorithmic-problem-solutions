using namespace std;
int checkMinAlloc(vector<int>& A, int mx) {
    int cnt = 0;
    
    int cummulative = 0;
    for (int i = 0; i < A.size(); ++i) {
        if (A[i] > mx) return INT_MAX;
        
        if (cummulative + A[i] > mx) {
            cnt += 1;
            cummulative = A[i];
        } else {
            cummulative += A[i];
        }
    }
    
    if (cummulative > 0) ++cnt;
    
    return cnt;
}

int Solution::books(vector<int> &A, int B) {
    if (B > A.size()) return -1;
    
    int low = INT_MAX;
    int high = 0;
    for (auto val : A) {
        low = min(low, val);
        high += val;
    }
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (checkMinAlloc(A, mid) <= B) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    return low;
}
