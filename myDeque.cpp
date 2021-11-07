#include "myDeque.h"
#include <stdexcept>
#include <iostream>

myDeque::myDeque() : head(nullptr), tail(nullptr), size(0) {}

myDeque::myDeque(myDeque * cpy) : head(nullptr), tail(nullptr), size(0) {
    if (cpy->is_empty()) return;

    item* itemFromSource = cpy->head;
    for (size_t i = 0; i < cpy->getSize(); i++) {
       pushR(itemFromSource->val);
       itemFromSource = itemFromSource->next;
    }
}

myDeque::~myDeque() {
    clear();
}

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

int &myDeque::operator[](size_t index) {
    check_pos(index);

    myDeque tmp(this);
    item* result;

    if (index <= size / 2) {
        clearL(index);
        result = head;
        for (size_t i = index; i-- > 0;)
            pushL(tmp.get(i));
    } else {
        clearR(index);
        result = tail;
        for (size_t i = index + 1; i < tmp.size; i++)
            pushR(tmp.get(i));
    }
    return result->val;
}

void myDeque::print() {
    myDeque tmp(this);
    for (size_t i = 0; i < size; i++)
        std::cout << tmp.popL() << " ";
    std::cout << std::endl;
}

void myDeque::clear() {
    if(is_empty()) return;
    clearL(size - 1);
}

void myDeque::clearL(size_t index) {
    check_pos(index);
    for (size_t i = 0; i < index; i++)
        popL();
}

void myDeque::clearR(size_t index) {
    check_pos(index);
    for (size_t i = size - 1; i > index; i--)
        popR();
}

size_t myDeque::getSize() const { return size; }

bool myDeque::is_empty() const { return head == nullptr; }

void myDeque::check_pos(size_t index) const {
    if (is_empty())
        throw std::runtime_error("Deque is empty.");
    if (index >= size)
        throw std::runtime_error("Index is out of Deque bounds.");
}