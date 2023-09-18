#include "StrL.h"

int StrL::getData(){
    return this->data;
}

void StrL::setData(int data) {
    this->data = data;
}

StrL *StrL::getNext() {
    return this->next;
}

void StrL::setNext(StrL *next) {
    this->next = next;
}