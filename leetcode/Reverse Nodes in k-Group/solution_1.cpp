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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) return head;
        
        ListNode* dummy = new ListNode();
        ListNode* prevStart = dummy;
        ListNode* currStart = head;
        
        while (currStart != NULL) {
            ListNode* tmp = currStart;
            for (int i = 0; i < k - 1; ++i) {
                if (tmp == NULL) break;
                tmp = tmp->next;
            }
            
            if (tmp == NULL) {
                prevStart->next = currStart;
                break;
            }
            
            ListNode* prev = currStart;
            ListNode* curr = currStart->next;
            for (int i = 0; i < k - 1; ++i) {
                ListNode* after = curr->next;
                curr->next = prev;
                prev = curr;
                curr = after;
            }
            prevStart->next = prev;
            prevStart = currStart;
            prevStart->next = NULL;
            currStart = curr;
        }
        
        return dummy->next;
    }
};