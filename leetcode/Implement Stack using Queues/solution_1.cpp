#include <queue>
using namespace std;

class MyStack {
    public:
        queue<int> q;
        queue<int> tmp;

        MyStack() {

        }

        void push(int x) {
            if (!q.size()) {
                q.push(x);
            } else {
                tmp.push(q.front());
                q.pop();
                q.push(x);
            }
        }

        int pop() {
            int val = q.front();
            q.pop();

            while (tmp.size() > 1) {
                q.push(tmp.front());
                tmp.pop();
            }

            swap(q, tmp);

            return val;
        }

        int top() {
            return q.front();
        }

        bool empty() {
            return q.size() == 0;
        }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
