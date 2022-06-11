/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) return head;
        
        int numNodes = 1;
        
        ListNode* last = head;
        while (last->next != NULL) {
            last = last->next;
            numNodes++;
        }
        
        int rotations = k % numNodes;
        if (!rotations) return head;
        int cutPos = numNodes - rotations;
        
        ListNode* cur = head;
        for (int i = 1; i < cutPos; ++i) {
            cur = cur->next;
        }
        
        ListNode* start = cur->next;
        cur->next = NULL;
        last->next = head;
        
        return start;
    }
};