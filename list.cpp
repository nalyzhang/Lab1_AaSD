#include "list.h"

void list::setTail(StrL *t) {
    this->tail = t;
}

StrL *list::getTail(){
    return this->tail;
}

StrL *list::getHead() {
    return this->head;
}

void list::setHead(StrL *h) {
    this->head = h;
}

void list::pop_front() { //удаление с начала
    if (this->head == nullptr) return;
    if (this->head == this->tail) {
        delete this->tail;
        this->head = this->tail = nullptr;
        return;
    }
    StrL* node = this->head;
    this->head = node->getNext();
    delete node;
}

void list::push_front(int data) {
    StrL* node = new StrL(data);
    node->setNext(head);
    head = node;
    if (tail == NULL) tail = node;
}

void list::pop_back() {
    if (tail == NULL) return;
    if (head == tail) {
        delete tail;
        head = tail = NULL;
        return;
    }
    StrL* node;
    for(node = head; node->getNext()->getNext() != NULL; node = node->getNext());
    node->setNext(NULL);
    delete tail;
    tail = node;
}

void list::push_back(int s) { //добавление в конец
    StrL* node = new StrL(s);
    if (this->getHead() == nullptr) this->setHead(node);
    if (this->getTail() != nullptr) this->getTail()->setNext(node);
    this->setTail(node);
}

StrL* list::getAt(int k) { //доступ к элементу
    if (k < 0) return nullptr;
    StrL* node = this->getHead();
    int n = 0;
    while (node && n != k && node->getNext()) {
        node = node->getNext();
        n++;
    }
    return (n == k) ? node : nullptr;
}

//вствка элемента
void list::insert(int k, int s){ //индекс k - индекс элемента, после которого нужно вставить объект
    StrL* left = getAt(k);
    if (left == nullptr) return;
    StrL* right = left->getNext();
    StrL* node = new StrL(s);
    left->setNext(node);
    node->setNext(right);
    if (right == nullptr) this->setTail(node);
}

//удаление промежуточного элемента
void list::earse(int k) {
    if (k < 0) return;
    if (k == 0) {
        pop_front();
        return;
    }
    StrL* left = this->getAt(k-1);
    StrL* node = left->getNext();
    if (node == nullptr) return;
    StrL* right = node->getNext();
    left->setNext(right);
    if (node == this->getTail()) this->setTail(left);
    delete node;
}
