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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode* before = head;
        ListNode* curr = head;
        ListNode* after = curr->next;
        
        while (after != NULL) {
            if (curr != before) {
                curr->next = before;
            } else {
                curr->next = NULL;
            }
            before = curr;
            curr = after;
            after = after->next;
        }
        
        curr->next = before;
        head = curr;
        
        return head;
    }
};