#include <utility>
#include <stack>

using namespace std;

class StockSpanner {
public:
    stack<pair<int, int>> steak;
    int cur_idx = 0;

    StockSpanner() {
    }
    
    int next(int price) {
        while (steak.size() && steak.top().first > price) {
            steak.pop();
        }

        int left_limiting_idx;
        if (!steak.size()) {
            left_limiting_idx = -1;
        } else {
            left_limiting_idx = steak.top().second;
        }
        
        int span = cur_idx - left_limiting_idx;
        steak.push({price, cur_idx});
        ++cur_idx;

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
