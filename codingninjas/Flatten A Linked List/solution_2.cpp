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
Node* merge(Node*, Node*);

Node* flattenLinkedList(Node* head) 
{
    if (head == NULL || head->next == NULL) return head;
    
    head->next = flattenLinkedList(head->next);
    
    return merge(head, head->next);
}

Node* merge(Node* a, Node* b) 
{
    if (b == NULL) return a;
    
    if (a->data > b->data) swap(a, b);
    
    Node* res = a;
    Node* other = b;
    Node* tmp = NULL;
    while (a != NULL && b != NULL) {
        tmp = NULL;
        while (a != NULL && a->data <= b->data) {
            tmp = a;
            a = a->child;
        }
        tmp->child = b;
        swap(a, b);
    }
    
    res->next = NULL, other->next = NULL;
    return res;
}

/*
 * Back to front approach, easier to see the intuition i guess.
 */