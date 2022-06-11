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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) return head;
        
        int numNodes = 1;
        
        ListNode* last = head;
        while (last->next != NULL) {
            last = last->next;
            numNodes++;
        }
        
        if (!(k % numNodes)) return head;
        
        last->next = head;
        for (int i = 1; i < (numNodes - k % numNodes); ++i) {
            head = head->next;
        }
        
        ListNode* tmp = head->next;
        head->next = NULL;
        
        return tmp;
    }
};