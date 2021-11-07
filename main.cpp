#include <iostream>
#include "myDeque.h"

void sort(myDeque&);

int main() {
    myDeque deque; size_t size;
    std::cout << "Enter numbers count:";
    std::cin >> size;
    for (size_t i = 0; i < size; i++) {
        deque.pushL(rand() % 1000);// NOLINT(cert-msc30-c, cert-msc50-cpp)
    }
    deque.print();
    sort(deque);
    deque.print();
}

void sort(myDeque& deque) {
    int tmp; size_t min;
    for (size_t i = 0; i < deque.getSize() - 1; i++) {
        min = i;
        for (size_t j = i + 1; j < deque.getSize(); j++)
            if (deque.get(j) < deque.get(min))
                min = j;

        tmp = deque.get(i);
        deque.set(deque.get(min), i);
        deque.set(tmp, min);
    }
}