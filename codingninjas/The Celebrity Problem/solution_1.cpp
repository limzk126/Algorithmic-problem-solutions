#include <bits/stdc++.h>

int findCelebrity(int n) {
    int cur = 0;
    for (int i = 1; i < n; ++i) {
        if (knows(i, cur)) {
            continue;
        }

        cur = i;
    }

    for (int i = 0; i < n; ++i) {
        if (i == cur) continue;

        if (knows(i, cur) && !knows(cur, i)) continue;

        return -1;
    }

    return cur;
}
