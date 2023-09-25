#ifndef L2_3_LIST_H
#define L2_3_LIST_H
#include "StrL.h"
#include <iostream>

class list {
public:
    StrL* head;
    StrL* tail;

public:
    list(){
        this->head = this->tail = nullptr;
    }

    ~list(){
        while (this->head != nullptr) pop_front();
    }

    void pop_front();

    void push_back(int s);

    StrL *getAt(int k);

    void insert(int k, int s);

    void earse(int k);

    void push_front(int data);

    void pop_back();
};

#endif
