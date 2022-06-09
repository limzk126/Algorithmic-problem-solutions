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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int carry = 0;
        int l1_length = 0;
        int l2_length = 0;
        ListNode* s1_start = l1;
        ListNode* s2_start = l2;
        ListNode* s1_head = new ListNode();
        s1_head->next = l1;
        ListNode* s2_head = new ListNode();
        s2_head->next = l2;
        while (l1 != NULL || l2 != NULL) {
            int sum = carry;
            if (l1 != NULL) {
                sum += l1->val;
            }
            
            if (l2 != NULL) {
                sum += l2->val;
            }
            
            if (sum >= 10) carry = 1;
            else carry = 0;
            
            if (l1 != NULL) {
                l1->val = sum % 10;
                l1 = l1->next;
                s1_head = s1_head->next;
                l1_length++;
            }
            if (l2 != NULL) {
                l2->val = sum % 10;
                l2 = l2->next;
                s2_head = s2_head->next;
                l2_length++;
            }
        }
        
        if (carry) {
            s1_head->next = new ListNode(1);
            s2_head->next = new ListNode(1);
        }
        if (l1_length > l2_length) return s1_start;
        return s2_start;
    }
};

/*
 * Time: O(max(n,m))
 * Space: O(1)
 */