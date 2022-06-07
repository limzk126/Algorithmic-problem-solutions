#include <bits/stdc++.h> 
int LongestSubsetWithZeroSum(vector < int > arr) {
    unordered_map<int, int> um;
    um[0] = -1;
    
    int cummulative = 0;
    int longest = 0;
    for (int i = 0; i < arr.size(); ++i) {
        cummulative += arr[i];
        if (um.count(cummulative)) {
            longest = max(longest, i - um[cummulative]);
        }
        
        if (!um.count(cummulative)) {
            um[cummulative] = i;
        }
    }
    
    return longest;
}