class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, size(nums) - 1);
    }
    
    int mergeSort(vector<int>& v, int start, int end) {
        if (start >= end) return 0;
        
        int mid = (start + end) / 2;
        
        int left = mergeSort(v, start, mid);
        int right = mergeSort(v, mid + 1, end);
        
        return merge(v, start, mid, end) + left + right;
    }
    
    int merge(vector<int>& v, int start, int mid, int end) {
        int num_inversions = 0;
        int i = start, j = mid + 1;
        while (i <= mid && j <= end) {
            if (((long long) v[i]) > ((long long) v[j] * 2)) {
                j++;
            } else {
                num_inversions += (j - (mid + 1));
                i++;
            }
        }
        
        if (i <= mid) {
            num_inversions += (mid - i + 1) * (end - mid);
        }
        
        vector<int> temp(end - start + 1, 0);
        i = start, j = mid + 1;
        int tar = 0;
        while (i <= mid && j <= end) {
            if (v[i] > v[j]) {
                temp[tar++] = v[j++];
            } else {
                temp[tar++] = v[i++];
            }
        }
        
        while (i <= mid) {
            temp[tar++] = v[i++];
        }
        while(j <= end) {
            temp[tar++] = v[j++];
        }
        
        for (int k = 0; k < size(temp); ++k) {
            v[start + k] = temp[k];
        }
        
        return num_inversions;
    }
};