#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x)
{
    unordered_map<int, int> um;
    um[0] = 1;
    
    int cummulative = 0;
    int num_subarrays = 0;
    for (int i = 0; i < arr.size(); ++i) {
        cummulative ^= arr[i];
        
        if (um.count(cummulative ^ x)) {
            num_subarrays += um[cummulative ^ x];
        }
        
        um[cummulative] += 1;
    }
    
    return num_subarrays;
}