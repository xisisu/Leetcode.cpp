//
// Created by Sisu on 11/29/2015.
//

/*
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack.
 */

#include <iostream>
#include <vector>
#include <string>
#include <stack>

class MinStack { // 28 ms
public:
    void push(int x) {
        cur.push(x);
        if (min.empty() || x <= min.top()) { min.push(x); }
    }

    void pop() {
        if (cur.empty()) { return; }
        if (min.top() == cur.top()) { min.pop(); }
        cur.pop();
    }

    int top() {
        return cur.top();
    }

    int getMin() {
        return min.top();
    }

private:
    std::stack<int> cur;
    std::stack<int> min;
};

int main() {
    MinStack s;
    std::vector<int> tests = {5,4,3,2,1,2,3,4,5};
    for (const auto & item : tests) {
        s.push(item);
        std::cout << s.top() << " " << s.getMin() << std::endl;
    }
    return 0;
}