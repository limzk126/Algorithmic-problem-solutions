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
        if (headA == NULL || headB == NULL) return NULL;
        
        ListNode* a = headA;
        ListNode* b = headB;
        while (a != b) {
            a = a == NULL ? headB : a->next;
            b = b == NULL ? headA : b->next;
        }
        
        return a;
    }
};

/*
 * when a ptr first encounter null, make the pointer now point to the start of the other list(The longer one).
 * The other ptr now has (m - n) left to traverse until it encounters null.
 * Once the other pointer reaches null, point it to the other list(The shorter one).
 * Now the two pointers have the same amount of nodes left to traverse. If there is an intersection, they
 * will encounter it at the same time.