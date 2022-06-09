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
        if (list1 == NULL) return list2;
        if (list2 == NULL) return list1;
        
        if (list1->val > list2->val) swap(list1, list2);
        ListNode* res = list1;
        
        while (list1 != NULL && list2 != NULL) {
            ListNode* tmp = NULL;
            while (list1 != NULL && list1->val <= list2->val) {
                tmp = list1;
                list1 = list1->next;
            }
            
            tmp->next = list2;
            swap(list1, list2);
        }
        
        return res;
    }
};

/*
 * l1 points to the smaller element while l2 points to the larger element.
 * Keep iterating l1 till the element iterated on is null or is larger than the element pointed by l2.
 * The element before l1 will now point to l2, then swap l1 and l2 as the element pointed by l1 is
 * guaranteed to be the larger one.
 */