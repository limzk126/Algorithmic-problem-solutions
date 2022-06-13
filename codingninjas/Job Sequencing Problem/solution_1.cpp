#include <algorithm>

bool comparator(vector<int> a, vector<int> b) {
    return a[1] > b[1];
}

int jobScheduling(vector<vector<int>> &jobs)
{
    sort(jobs.begin(), jobs.end(), comparator);
    
    int maxi = -1;
    for (int i = 0; i < jobs.size(); ++i) {
        maxi = max(maxi, jobs[i][0]);
    }
    
    vector<bool> slot(maxi + 1, false);
    
    int sum = 0;
    for (int i = 0; i < jobs.size(); ++i) {
        for (int j = jobs[i][0]; j > 0; j--) {
            if (!slot[j]) {
                slot[j] = true;
                sum += jobs[i][1];
                break;
            } 
        }
    }
    
    return sum;
}
