#include <iostream>
#include "myDeque.h"
#include "Windows.h"

void sort(myDeque&);

int main() {
    srand((unsigned)time(nullptr));// NOLINT(cert-msc51-cpp)
    myDeque deque; size_t size;
    std::cout << "Enter numbers count:";
    std::cin >> size;
    for (size_t i = 0; i < size; i++)
        deque.pushL(rand() % 1000);// NOLINT(cert-msc50-cpp)

    std::cout << "Unsorted deque: " << std::endl;
    deque.print();

    long long t_s, t_e;
    t_s = GetTickCount();
    sort(deque);
    t_e = GetTickCount();
    std::cout << "\nSort time (ms): " << t_e - t_s << std::endl;

    std::cout << "\nSorted deque: " << std::endl;
    deque.print();
}

/**
 * Simple Selection Sort for myDeque
 * @public
 * @param myDeque& deque
 * @returns void
 */
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