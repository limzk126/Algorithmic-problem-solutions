class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int last[128] = {}, sum = 0;
        for (int i = 0; i < garbage.size(); ++i) {
            for (auto g : garbage[i]) {
                last[g] = i;
            }
            sum += garbage[i].size();
        }
        
        for (int i = 1; i < travel.size(); ++i) {
            travel[i] += travel[i - 1];
        }
        
        for (auto c : "PGM") {
            if (last[c]) sum += travel[last[c] - 1];
        }
        
        return sum;
    }
};
