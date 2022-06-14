#include <algorithm>

struct activity {
    int start;
    int end;
};

bool comparator(activity a, activity b) {
    return a.end < b.end;
}

int maximumActivities(vector<int> &start, vector<int> &finish) {
    vector<activity> v(start.size());
    
    for (int i = 0; i < start.size(); ++i) {
        v[i].start = start[i];
        v[i].end = finish[i];
    }
    
    sort(v.begin(), v.end(), comparator);
    
    int res = 0;
    int curEnd = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i].start >= curEnd) {
            res++;
            curEnd = v[i].end;
        }
    }
    
    return res;
}