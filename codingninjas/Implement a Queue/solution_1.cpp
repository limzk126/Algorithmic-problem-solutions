class Queue {
public:
    struct Node {
        int val;
        Node* next;

        Node(int _val): val(_val), next(nullptr) {};
    };

    Node* head;
    Node* tail;

    Queue() {
        // Implement the Constructor
        head = nullptr;
        tail = head;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if (head == nullptr) return true;

        return false;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if (isEmpty()) {
            head = new Node(data);
            tail = head;
            return;
        }
        
        tail->next = new Node(data);
        tail = tail->next;
    }

    int dequeue() {
        // Implement the dequeue() function
        if (isEmpty()) {
            return -1;
        }

        int val = head->val;
        head = head->next;

        return val;
    }

    int front() {
        // Implement the front() function
        if (isEmpty()) {
            return -1;
        }

        return head->val;
    }
};
