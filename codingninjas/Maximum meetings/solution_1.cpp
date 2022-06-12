#include <algorithm>

struct meeting {
    int start;
    int end;
    int pos;
};

bool comparator (meeting a, meeting b) {
    if (a.end < b.end) return true;
    else if (a.end > b.end) return false;
    else if (a.pos < b.pos) return true;
    else return false;
}

vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    int n = start.size();
    vector<meeting> v(n);
    for (int i = 0; i < n; ++i) {
        v[i].start = start[i];
        v[i].end = end[i];
        v[i].pos = i + 1;
    }
    
    sort(v.begin(), v.end(), comparator);
    
    int limit = v[0].end;
    vector<int> res;
    res.push_back(v[0].pos);
    
    for (int i = 1; i < n; ++i) {
        if (v[i].end == limit) {
            continue;
        }
        
        if (v[i].start <= limit) {
            continue;
        }
        
        limit = v[i].end;
        res.push_back(v[i].pos);
    }
    
    return res;
}

/*
 * Hint: Reduce the problem by looking at the end of the meetings.
 */