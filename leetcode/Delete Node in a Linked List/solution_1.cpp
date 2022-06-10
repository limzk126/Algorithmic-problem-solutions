/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* nextNext = node->next->next;
        int nextVal = node->next->val;
        node->val = nextVal;
        node->next = nextNext;
    }
};