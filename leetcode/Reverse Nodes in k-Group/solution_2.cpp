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
        if (head == NULL || k == 1) return head;
        
        ListNode* dummy = new ListNode();
        dummy->next = head;
        
        ListNode* prev = dummy;
        ListNode* cur = dummy;
        ListNode* after = dummy;
        
        int cnt = 0;
        while (cur->next != NULL) {
            cur = cur->next;
            ++cnt;
        }
        
        while  (cnt >= k) {
            cur = prev->next;
            after = cur->next;
            for (int i = 1; i < k; ++i) {
                cur->next = after->next;
                after->next = prev->next;
                prev->next = after;
                after = cur->next;
            }
            prev = cur;
            cnt -= k;
        }
        
        return dummy->next;
    }
};

/*
 * First we find out the length of the linkedlist.
 * We create a dummy node which points to the first node in the sequence.
 * We create a prev pointer which points to this dummy node.
 * The prev pointer's role is to be pointer to the last node of the previous sequence.
 * We create a cur pointer whose role is to point to the first node of the current sequence (eventually will be last).
 * At each iteration in the sequence, 
 * 1. The cur pointer's next will point to after's next, which serves to track the next node after can point to,
 *    and also to eventually point to the first node of the next sequence.
 * 2. The prev pointer's next will point to the 'current' node in the sequence, where the after's next will point to.
 *    This serves eventually point to the last node of the current sequence (eventually will be first).
 *    Hence this causes the last node of previous sequence to point to the first node of current reversed sequence.
 * At the end of each iteration, 
 * prev will now be assigned to point at the node curr is pointing to (The last node of current sequence).
 * curr will now be assigned to point at the start of the next sequence (prev->next).
 */