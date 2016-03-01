//
// Created by Sisu on 2/29/2016.
//

/*
 * Implement the following operations of a stack using queues.
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * empty() -- Return whether the stack is empty.
 * Notes:
 * You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is
 * empty operations are valid. Depending on your language, queue may not be supported natively. You may simulate a
 * queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
 * You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
 * Update (2015-06-11):
 * The class name of the Java function had been updated to MyStack instead of Stack.
 */

#include <iostream>
#include <queue>

class Stack { // 0 ms
public:
    Stack() {};
    ~Stack() {};

    // Push element x onto stack.
    void push(int x) {
        _queue.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        while (_queue.size() > 1) {
            _tmp.push(_queue.front());
            _queue.pop();
        }
        _queue.pop();
        _queue.swap(_tmp);
    }

    // Get the top element.
    int top() {
        while (_queue.size() > 1) {
            _tmp.push(_queue.front());
            _queue.pop();
        }
        int res = _queue.front();
        _tmp.push(_queue.front());
        _queue.pop();
        _queue.swap(_tmp);
        return res;
    }

    // Return whether the stack is empty.
    bool empty() {
        return _queue.empty();
    }

private:
    std::queue<int> _queue, _tmp;
};

class Stack2 {
public:
    void push(int x) {
        _tmp.push(x);
        while (!_queue.empty()) {
            _tmp.push(_queue.front());
            _queue.pop();
        }
        _queue.swap(_tmp);
    }

    void pop() {
        _queue.pop();
    }

    int top() {
        return _queue.front();
    }

    bool empty() {
        return _queue.empty();
    }

private:
    std::queue<int> _queue, _tmp;
};

int main() {
    Stack s;
    for (int i = 0; i < 3; ++i) {
        s.push(i);
    }
    for (int i = 0; i < 3; ++i) {
        std::cout << s.top() << std::endl;
        s.pop();
    }

    return 0;
}