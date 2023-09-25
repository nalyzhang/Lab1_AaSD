#include "list.h"

void list::pop_front() { //удаление с начала
    if (this->head == nullptr) return;
    if (this->head == this->tail) {
        delete this->tail;
        this->head = this->tail = nullptr;
        return;
    }
    StrL* node = this->head;
    this->head = node->next;
    delete node;
}

void list::push_front(int data) {
    StrL* node = new StrL(data);
    node->next = head;
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
    for(node = head; node->next->next != NULL; node = node->next);
    node->next = NULL;
    delete tail;
    tail = node;
}

void list::push_back(int s) { //добавление в конец
    StrL* node = new StrL(s);
    if (this->head == nullptr) this->head = node;
    if (this->tail != nullptr) this->tail->next = node;
    this->tail = node;
}

StrL* list::getAt(int k) { //доступ к элементу
    if (k < -1) return nullptr;
    if (k == -1) return this->head;
    StrL* node = this->head;
    int n = 0;
    while (node && n != k && node->next) {
        node = node->next;
        n++;
    }
    return (n == k) ? node : nullptr;
}

//вствка элемента
void list::insert(int k, int s){ //индекс k - индекс элемента, после которого нужно вставить объект
    StrL* left = getAt(k);
    if (left == nullptr) return;
    StrL* right = left->next;
    StrL* node = new StrL(s);
    left->next = node;
    node->next = right;
    if (right == nullptr) this->tail = node;
}

//удаление промежуточного элемента
void list::earse(int k) {
    if (k < 0) return;
    if (k == 0) {
        pop_front();
        return;
    }
    StrL* left = this->getAt(k-1);
    StrL* node = left->next;
    if (node == nullptr) return;
    StrL* right = node->next;
    left->next = right;
    if (node == this->tail) this->tail = left;
    delete node;
}
