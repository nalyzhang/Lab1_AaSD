#ifndef L2_3_STRL_H
#define L2_3_STRL_H


class StrL {
private:
    int data;
    StrL* next;

public:
    StrL(int n) {
        this->data = n;
        this->next = nullptr;
    }

    ~StrL() {
        this->data = 0;
    }

    int getData();

    void setData(int data);

    StrL *getNext();

    void setNext(StrL *next);
};

#endif
