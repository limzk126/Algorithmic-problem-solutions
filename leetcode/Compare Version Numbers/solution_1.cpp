#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int compareVersion(string version1, string version2) {
            int i = 0, j = 0;
            while (i < version1.size() || j < version2.size()) {
                string rev1 = "";
                while (i < version1.size() && version1[i] == '0') ++i;
                while (i < version1.size() && version1[i] != '.') rev1 += version1[i++];
                ++i; // Skip the '.'

                string rev2 = "";
                while (j < version2.size() && version2[j] == '0') ++j;
                while (j < version2.size() && version2[j] != '.') rev2 += version2[j++];
                ++j; // Skip the '.'

                if (rev1.size() < rev2.size()) return -1;
                if (rev1.size() > rev2.size()) return 1;
                if (rev1 < rev2) return -1;
                if (rev1 > rev2) return 1;
            }

            return 0;
        }
};
