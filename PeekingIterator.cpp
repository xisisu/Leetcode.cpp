//
// Created by xisisu on 6/19/16.
//

/*
 * Given an Iterator class interface with methods: next() and hasNext(), design and implement a PeekingIterator that
 * support the peek() operation -- it essentially peek() at the element that will be returned by the next call to
 * next().
 *
 * Here is an example. Assume that the iterator is initialized to the beginning of the list: [1, 2, 3].
 *
 * Call next() gets you 1, the first element in the list.
 *
 * Now you call peek() and it returns 2, the next element. Calling next() after that still return 2.
 *
 * You call next() the final time and it returns 3, the last element. Calling hasNext() after that should return false.
 *
 * Hint:
 *
 * Think of "looking ahead". You want to cache the next element.
 * Is one variable sufficient? Why or why not?
 * Test your design with call order of peek() before next() vs next() before peek().
 * For a clean implementation, check out Google's guava library source code.
 */

#include <iostream>
#include <vector>

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const std::vector<int>& nums);
    Iterator(const Iterator& iter);
    virtual ~Iterator();
    // Returns the next element in the iteration.
    int next();
    // Returns true if the iteration has more elements.
    bool hasNext() const;
};

class PeekingIterator : public Iterator {
private:
    int _peek;
    bool _peeked;

public:
    PeekingIterator(const std::vector<int>& nums) : Iterator(nums) { // 4 ms
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        _peeked = false;
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        if (!_peeked) {
            _peek = this->next();
            _peeked = true;
        }
        return _peek;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        if (_peeked) {
            _peeked = false;
            return _peek;
        }
        return this->next();
    }

    bool hasNext() const {
        return _peeked ? true : this->hasNext();
    }
};
