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
    bool isPalindrome(ListNode* head) {
        if (head->next == NULL) return true;
        
        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* after = head->next;;
        
        int numNodes = 0;
        while (cur != NULL) {
            cur = cur->next;
            ++numNodes;
        }
        
        cur = head;
        
        for (int i = 0; i < numNodes / 2; ++i) {
            cur->next = prev;
            prev = cur;
            cur = after;
            after = after->next;
        }
        
        ListNode* backward = prev;
        ListNode* forward = numNodes & 1 ? after : cur;
        
        while (backward != NULL && forward != NULL) {
            if (backward->val != forward->val) return false;
            
            backward = backward->next;
            forward = forward->next;
        }
        
        return true;
    }
};

/*
 * time: O(N)
 * space: O(1)
 */