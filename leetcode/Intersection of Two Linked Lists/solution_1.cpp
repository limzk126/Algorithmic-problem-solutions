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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a_ptr = headA;
        ListNode* b_ptr = headB;
        
        int m = 0;
        while (a_ptr != NULL) {
            a_ptr = a_ptr->next;
            m++;
        }
        int n = 0;
        while (b_ptr != NULL) {
            b_ptr = b_ptr->next;
            n++;
        }
        
        if (m < n) {
            swap(headA, headB);
            swap(m, n);
        }
        
        for (int i = 0; i < (m - n); ++i) {
            headA = headA->next;
        }
        
        while (headA != NULL && headB != NULL && headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        
        return headA;
    }
};