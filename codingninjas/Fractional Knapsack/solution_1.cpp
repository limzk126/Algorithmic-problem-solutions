#include <algorithm>

bool comparator(pair<int, int> a, pair<int, int> b) {
    return ((double) a.second) / a.first > ((double) b.second) / b.first;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    sort(items.begin(), items.end(), comparator);
    
    double res = 0.0;
    for (int i = 0; i < items.size(); ++i) {
        if (w > items[i].first) {
            res += items[i].second;
            w -= items[i].first;
            continue;
        }
        res += ((double) items[i].second) / items[i].first * w;
        w = 0;
    }
    
    return res;
}