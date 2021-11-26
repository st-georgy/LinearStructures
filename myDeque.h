#ifndef LINEARSTRUCTURES_MYDEQUE_H
#define LINEARSTRUCTURES_MYDEQUE_H

class myDeque {
    struct item {
        item *next, *prev;
        int val;
        /**
         * @constructor
         * @param int& v
         * @this item
         */
        explicit item(const int& v): next(nullptr), prev(nullptr), val(v){}
    };
private:
    item *head, *tail;
    size_t size;
public:
    myDeque();
    explicit myDeque(myDeque*);
    ~myDeque();

    bool is_empty() const; // NOLINT
    void check_pos(size_t) const;
    size_t getSize() const; // NOLINT

    void pushL(const int&);
    void pushR(const int&);
    int popL();
    int popR();
    void clear();
    void clearL(size_t);
    void clearR(size_t);

    void set(int, size_t);
    int get (size_t);

    void print();
};

#endif //LINEARSTRUCTURES_MYDEQUE_H