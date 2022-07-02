#include <stack>
using namespace std;

void insertStack(stack<int> &stack, int n) {
    if (stack.empty() || (!stack.empty() && stack.top() < n)) {
        stack.push(n);
        return;
    }

    int num = stack.top();
    stack.pop();

    insertStack(stack, n);

    stack.push(num);
}   


void sortStack(stack<int> &stack)
{
    if (stack.empty()) return;

    int num = stack.top();
    stack.pop();

    sortStack(stack);
    insertStack(stack, num);
}
