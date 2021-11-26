#include "myDeque.h"
#include <stdexcept>
#include <iostream>

/**
 * @constructor
 * @this myDeque
 */
myDeque::myDeque() : head(nullptr), tail(nullptr), size(0) {}

/**
 * @constructor
 * @param myDeque* cpy
 * @this myDeque
 */
myDeque::myDeque(myDeque * cpy) : head(nullptr), tail(nullptr), size(0) {
    if (cpy->is_empty()) return;

    item* itemFromSource = cpy->head;
    for (size_t i = 0; i < cpy->getSize(); i++) {
       pushR(itemFromSource->val);
       itemFromSource = itemFromSource->next;
    }
}

/**
 * @destructor
 * @this myDeque
 */
myDeque::~myDeque() {
    clear();
}

/**
 * Add element to myDeque (left)
 * @public
 * @param int& value
 * @this myDeque
 * @returns void
 */
void myDeque::pushL(const int& value) {
    item* pushItem = new item(value);
    if (head == nullptr)
        head = tail = pushItem;
    else {
        pushItem->next = head;
        head->prev = pushItem;
        head = pushItem;
    }
    ++size;
}

/**
 * Add element to myDeque (right)
 * @public
 * @param int& value
 * @this myDeque
 * @returns void
 */
void myDeque::pushR(const int& value) {
    item* pushItem = new item(value);
    if (head == nullptr)
        head = tail = pushItem;
    else {
        pushItem->prev = tail;
        tail->next = pushItem;
        tail = pushItem;
    }
    ++size;
}

/**
 * Remove first element (left) from myDeque
 * @public
 * @this myDeque
 * @returns int
 */
int myDeque::popL() {
    if (is_empty()) throw std::runtime_error("Deque is empty!");

    int result = head->val;
    item* tmp = head;

    head = tmp->next;
    if (head != nullptr)
        head->prev = nullptr;

    delete tmp;
    --size;

    return result;
}

/**
 * Remove last element (right) from myDeque
 * @public
 * @this myDeque
 * @returns int
 */
int myDeque::popR() {
    if (is_empty()) throw std::runtime_error("Deque is empty!");

    int result = tail->val;
    item* tmp = tail;

    tail = tmp->prev;
    if (tail != nullptr)
        tail->next = nullptr;

    delete tmp;
    --size;

    return result;
}

/**
 * Change element[index] value
 * @public
 * @param int value
 * @param size_t index
 * @this myDeque
 * @returns void
 */
void myDeque::set(int value, size_t index) {
    check_pos(index);

    myDeque tmp(this);
    if (index <= size / 2) {
        clearL(index);
        head->val = value;
        for (size_t i = index; i-- > 0;)
            pushL(tmp.get(i));
    } else {
        clearR(index);
        tail->val = value;
        for (size_t i = index + 1; i < tmp.size; i++)
            pushR(tmp.get(i));
    }
}

/**
 * Get element[index] value
 * @public
 * @param index
 * @this myDeque
 * @returns int
 */
int myDeque::get(size_t index) {
    check_pos(index);

    myDeque tmp(this);
    int result;

    if (index <= size / 2) {
        tmp.clearL(index);
        result = tmp.popL();
    } else {
        tmp.clearR(index);
        result = tmp.popR();
    }

    return result;
}

/**
 * Prints all values in myDeque
 * @public
 * @this myDeque
 * @returns void
 */
void myDeque::print() {
    myDeque tmp(this);
    for (size_t i = 0; i < size; i++)
        std::cout << tmp.popL() << " ";
    std::cout << std::endl;
}

/**
 * Clears myDeque
 * @public
 * @this myDeque
 * @returns void
 */
void myDeque::clear() {
    if(is_empty()) return;
    clearL(size - 1);
}

/**
 * Clears myDeque from beginning (left) to index
 * @public
 * @param size_t index
 * @this myDeque
 * @returns void
 */
void myDeque::clearL(size_t index) {
    check_pos(index);
    for (size_t i = 0; i < index; i++)
        popL();
}

/**
 * Clears myDeque from end (right) to index
 * @public
 * @param size_t index
 * @this myDeque
 * @returns void
 */
void myDeque::clearR(size_t index) {
    check_pos(index);
    for (size_t i = size - 1; i > index; i--)
        popR();
}

/**
 * Get size of myDeque
 * @public
 * @this myDeque
 * @returns size_t
 */
size_t myDeque::getSize() const { return size; }

/**
 * Checks if myDeque is empty
 * @public
 * @this myDeque
 * @returns bool
 */
bool myDeque::is_empty() const { return head == nullptr; }

/**
 * Checks if element on position [index] is null
 * @public
 * @param size_t index
 * @this myDeque
 * @returns void
 */
void myDeque::check_pos(size_t index) const {
    if (is_empty())
        throw std::runtime_error("Deque is empty.");
    if (index >= size)
        throw std::runtime_error("Index is out of Deque bounds.");
}