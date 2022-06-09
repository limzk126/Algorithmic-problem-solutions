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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ptr = NULL;
        ListNode* head = NULL;
        if (list1 == NULL) return list2;
        if (list2 == NULL) return list1;
        
        while (list1 != NULL && list2 != NULL) {
            ListNode* next1 = list1->next;
            ListNode* next2 = list2->next;
            
            if (list1->val < list2->val) {
                if (ptr == NULL) {
                    ptr = list1;
                    head = list1;
                } else {
                    ptr->next = list1;
                    ptr = ptr->next;
                }
                list1 = next1;                    
            } else {
                if (ptr == NULL) {
                    ptr = list2;
                    head = list2;
                } else {
                    ptr->next = list2;
                    ptr = ptr->next;
                }
                list2 = next2;
            }
        }
        if (list1 == NULL) {
            ptr->next = list2;
        } else {
            ptr->next = list1;
        }
        
        return head;
    }
};