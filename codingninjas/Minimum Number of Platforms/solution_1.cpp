#include <algorithm>

struct station {
    int start;
    int end;
};

bool comparator(station a, station b) {
    if (a.start < b.start) {
        return true;
    }
    return false;
}

int calculateMinPatforms(int at[], int dt[], int n) {
    unordered_map<int, vector<station>> um;
    for (int i = 0; i < n; i++) {
        if (!um.count(at[i])) {
            vector<station> tmp;
            station s = {at[i], dt[i]};
            tmp.push_back(s);
            um[at[i]] = tmp;
        } else {
            station s = {at[i], dt[i]};
            um[at[i]].push_back(s);
        }
    }
    
    vector<int> ends(2360);
    int mx = 0;
    int curEnds = 0;
    for (int i = 0; i <= 2359; ++i) {
        if (um.count(i)) {
            mx = max(mx, curEnds + (int)um[i].size());
            for (int j = 0; j < um[i].size(); ++j) {
                ends[um[i][j].end]++;
                curEnds++;
            }
            
            um.erase(i);
        }
        
        curEnds -= ends[i];
        ends[i] = 0;
    }
    
    return mx;
}