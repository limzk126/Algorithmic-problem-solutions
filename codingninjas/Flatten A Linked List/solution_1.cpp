#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

*****************************************************************/

Node* flattenLinkedList(Node* head) 
{
    if (head->next == NULL) return head;
    
    Node* xiage = head->next;
    Node* a = head;
    Node* b = xiage;
    if (a->data > b->data) swap(a, b);
    Node* res = a;
    Node* other = b;
    while (xiage != NULL) {
        a = res;
        b = xiage;
        if (a->data > b->data) swap(a, b);
        res = a;
        other = b;
        while (a != NULL && b != NULL) {
            Node* tmp = NULL;
            while (a != NULL && a->data <= b->data) {
                tmp = a;
                a = a->child;
            }
            
            tmp->child = b;
            swap(a, b);
        }
        xiage = xiage->next;
        res->next = NULL;
        other->next = NULL;
        
    }
    
    return res;
}
