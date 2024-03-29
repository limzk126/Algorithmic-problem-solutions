#include <algorithm>

int calculateMinPatforms(int at[], int dt[], int n) {
    sort(at, at + n);
    sort(dt, dt + n);
    
    int plat_needed = 1, res = 1;
    int i = 1, j = 0;
    while (i < n && j < n) {
        if (at[i] <= dt[j]) {
            ++plat_needed;
            ++i;
        } else if (at[i] > dt[j]) {
            --plat_needed;
            ++j;
        }
        
        res = max(res, plat_needed);
    }
    
    return res;
}