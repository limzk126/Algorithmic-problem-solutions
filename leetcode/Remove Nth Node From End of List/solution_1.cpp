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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* leader = head;
        ListNode* follower = head;
        
        int cnt = n;
        while (leader->next != NULL && cnt) {
            leader = leader->next;
            cnt--;
        }
        
        if (cnt) {
            head = head->next;
            return head;
        }
        
        // num of nodes >= n at this point
        
        while (leader->next != NULL) {
            leader = leader->next;
            follower = follower->next;
        }
        
        follower->next = follower->next->next;
        return head;
    }
};