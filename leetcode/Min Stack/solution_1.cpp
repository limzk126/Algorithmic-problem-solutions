#include <stack>
#include<climits>

using namespace std;

class MinStack {
    public:
        stack<int> steak;
        stack<int> min_steak;

        MinStack() {
        }

        void push(int val) {
            steak.push(val);

            if (min_steak.size()) {
                int prev_min = min_steak.top();

                min_steak.push(min(prev_min, val));
            } else {
                min_steak.push(val);
            }
        }

        void pop() {
            steak.pop();
            min_steak.pop();
        }

        int top() {
            return steak.top(); 
        }

        int getMin() {
            return min_steak.top();
        } 
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
