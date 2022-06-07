class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashSet;
        
        for (auto num : nums) {
            hashSet.insert(num);
        }
        
        int longest = 0;
        
        for (auto num: nums) {
            if (hashSet.count(num - 1)) {
                continue;
            }
            
            int i = num;
            int counter = 0;
            while (hashSet.count(i)) {
                counter++;
                i++;
            }
            
            longest = max(longest, counter);
        }
        
        return longest;
    }
};

/*
 * One pass the array to insert all elements into the unordered set.
 * Iterate through the array and check if the element has any element one less than itself.
 * If there isn't, it means this element is the smallest in a consecutive sequence and we can
 * increment from that element until the end of the consecutive sequence to find its length.
 * This is done to prevent an O(N^2) algorithm.
 */