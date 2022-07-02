#include <stack>
using namespace std;

class MyQueue {
    public:
        stack<int> out;
        stack<int> in;

        MyQueue() {

        }

        void push(int x) {
            in.push(x); 
        }

        int pop() {
            if (!out.size()) {
                while (in.size()) {
                    out.push(in.top());
                    in.pop();
                }
            }

            int val = out.top();
            out.pop();

            return val;
        }

        int peek() {
            if (!out.size()) {
                while (in.size()) {
                    out.push(in.top());
                    in.pop();
                }
            }

            return out.top(); 
        }

        bool empty() {
            return out.size() == 0 && in.size() == 0; 
        }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
