#ifndef LINEARSTRUCTURES_MYDEQUE_H
#define LINEARSTRUCTURES_MYDEQUE_H

class myDeque {
    struct item {
        item *next, *prev;
        int val;
        explicit item(const int& v): next(nullptr), prev(nullptr), val(v){}
    };
private:
    item *head, *tail;
    size_t size;
public:
    myDeque();
    explicit myDeque(myDeque*);
    ~myDeque();

    bool is_empty() const;
    void check_pos(size_t) const;
    size_t getSize() const;

    void pushL(const int&);
    void pushR(const int&);
    int popL();
    int popR();
    void clear();
    void clearL(size_t);
    void clearR(size_t);

    void set(int, size_t);
    int get (size_t);

    int & operator[] (size_t);

    void print();
};

/*void myDeque::set(int val, size_t index) {
    check_pos(index);

    myDeque tmp(this);
    if (index <= size / 2) {
        clearL(index);
        head->val = val;
        for (size_t i = index; i >= 0; i--)
            pushL(tmp.get(i));
    } else {
        clearR(index);
        tail->val = val;
        for (size_t i = ++index; i < size; i++)
            pushR(tmp.get(i));
    }
}

int myDeque::get(size_t index) {
    check_pos(index);

    if (index == 0) return head->val;
    if (index == size - 1) return tail->val;

    myDeque tmp(this);
    int result = 0;

    if (index <= size / 2) {
        tmp.clearL(index - 1);
        result = tmp.popL();
    }
    else {
        tmp.clearR(index - 1);
        result = tmp.popR();
    }

    return result;
}*/

#endif //LINEARSTRUCTURES_MYDEQUE_H