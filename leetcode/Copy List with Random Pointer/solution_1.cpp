/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* cur = head;
        
        while (cur != NULL) {
            Node* after = cur->next;
            Node* tmp = new Node(cur->val);
            cur->next = tmp;
            tmp->next = after;
            
            cur = after;
        }
        
        cur = head;
        while (cur != NULL) {
            cur->next->random = cur->random == NULL ? NULL : cur->random->next;
            
            cur = cur->next->next;
        }
        
        cur = head;
        Node* dummy = new Node(0);
        Node* prev = dummy;
        while (cur != NULL) {
            Node* after = cur->next->next;
            prev->next = cur->next;
            cur->next = after;
            
            // Next Iterations
            cur = after;
            prev = prev->next;
        }
        
        return dummy->next;
    }
};

/*
 * Example LinkedList: 1->2->3->4->4
 * First we create a deep copy Node after each Node in the original LL.
 * We get 1->1->2->2->3->3->4->4
 * Next we link each deep copy Node's random to the correct Node.
 * We can do that as the original Node's random's next is what we want.
 * We unlink both the deep copy nodes and original nodes to form a deep copy LL and original LL.
 */