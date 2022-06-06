class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int x = 0, y = 0, cx = 0, cy = 0;
        
        for (int i = 0; i < size(nums); ++i) {
            if (!cx && nums[i] != y) {
                x = nums[i];
            }
            if (!cy && nums[i] != x) {
                y = nums[i];
            }
            if (nums[i] == x) {
                cx++;
                continue;
            }
            if (nums[i] == y) {
                cy++;
                continue;
            }
            
            cx--, cy--;
        }
        
        vector<int> res;
        int cntX = 0, cntY = 0;
        for (auto num : nums) {
            if (num == x) cntX++;
            if (num == y) cntY++;
        }
        if (cntX > nums.size() / 3 && cx) res.push_back(x);
        if (cntY > nums.size() / 3 && cy) res.push_back(y);
        
        return res;
    }
};

/*
 * Use a modified version of Boyer Moore's algorithm.
 * Can be at most two majority elements.
 * We imagine forming tuples of 3, e.g {1, 2, 4}
 * Only when an element is foreign to the two elements currently tracked, it can remove one from both.
 * Hence, we can conclude the tuples of 3 have distinct elements in them.
 * A tuple is only formed when pairing/cancellation happens. When an element is a currently tracked one,
 * we increment its stack (visualize each tracked element as being in a stack). When either stack is empty,
 * the current element has to be put in one of the stacks, and cancellation cannot take place.
 * A tuple will keep forming as long as there are 3 distinct elements (two from each stack and one currently
 * being iterated on). Hence the leftovers at the end that cannot form tuples must be at most 2 distinct,
 * otherwise it contradicts our argument and more tuples should have been formed.
 * A majority element can appear at most once in a tuple and at most floor of n/3 tuples can be formed.
 * Therefore if there is a majority element, it must appear at the end as leftovers (aka in the stacks).