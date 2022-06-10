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
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return false;
        
        ListNode* hare = head->next;
        ListNode* tortoise = head;
        
        while (hare != NULL && hare->next != NULL && hare != tortoise) {
            tortoise = tortoise->next;
            hare = hare->next->next;
        }
        
        if (hare != tortoise) return false;
        
        return true;
    }
};

/*
 * Floyd's cycle detection algorithm (tortoise and hare)
 * Time: O(lambda + mu) 
 * lambda is the length of the cycle, mu is the length from start to the entrance of the cycle.
 * When the tortoise enters the cycle, the distance between the hare and tortoise is less than lamba.
 * This gap is closed by 1 every iteration.
 */