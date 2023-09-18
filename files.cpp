#include "files.h"
#include <iomanip>

/*
    1	добавление в конец списка \/
	2	добавление в начало списка \/
	3	удаление последнего элемента \/
	4	удаление первого элемента \/
	5	добавление элемента по индексу (вставка перед элементом, который был ранее доступен по этому индексу) \/
	6	получение элемента по индексу \/
	7	удаление элемента по индексу \/
	8	получение размера списка \/
	9	удаление всех элементов списка \/
	10	замена элемента по индексу на передаваемый элемент \/
	11	проверка на пустоту списка \/
	12	меняет порядок элементов в списке на обратный \/
	13	вставка другого списка в список, начиная с индекса \/
	14	вставка другого списка в конец \/
	15	вставка другого списка в начало \/
	16	проверка на содержание другого списка в списке, можно сделать целочисленного типа
	17	поиск первого вхождения другого списка в список
	18	поиск последнего вхождения другого списка в список
	19	обмен двух элементов списка по индексам
 */

void files::readIn(list& list) {
    if (this->in.is_open() == 1) {
        int node;
        if (this->in.eof() == 0) {
            while(this->in.eof() == 0) {
                this->in >> node;
                list.push_back(node);
            }
        }
    }
}

list files::inputNewList(){
    list list;
    if (this->inL.is_open() == 1) {
        int node;
        if (this->inL.eof() == 0) {
            while(this->inL.eof() == 0) {
                this->inL >> node;
                list.push_back(node);
            }
        }
    }
    return list;
}

void files::printList(list list) {
    std::cout << "Полученный список:" << std::endl;
    for (StrL *node = list.getHead(); node != nullptr; node = node->getNext()) {
        this->out << node->getData() << " ";
    }
    this->out << std::endl;
}

void files::fuction1(list& list){
    std::cout << "Введите число, которое хотите добавить в список" << std::endl;
    int n;
    std::cin >> n;
    list.push_back(n);
}

void files::fuction2(list &list) {
    std::cout << "Введите число, которое хотите добавить в список" << std::endl;
    int n;
    std::cin >> n;
    list.push_front(n);
}

void files::fuction3(list &list) {
    list.pop_back();
}

void files::function4(list& list) {
    list.pop_front();
}

void files::function5(list& list) {
    std::cout << "Введите число, которое хотите добавить в список" << std::endl;
    int n;
    std::cin >> n;
    std::cout << "Введите номер элемента, перед которым хотите вставить число" << std::endl;
    int k;
    std::cin >> k;
    list.insert(k - 1, n);
}

int files::function6(list& list) {
    std::cout << "Введите номер элемента, чье значение хотите получить" << std::endl;
    int k;
    std::cin >> k;
    StrL* node = list.getAt(k);
    return node->getData();
}

void files::function7(list& list) {
    std::cout << "Введите номер элемента, который хотите удалить" << std::endl;
    int k;
    std::cin >> k;
    list.earse(k);
}

int files::function8(list &list) {
    int count;
    for (StrL* node = list.getHead(); node->getNext() != NULL; node->getNext()) count++;
    return count;
}

void files::function9(list &list) {
    while(list.getHead() != NULL) list.pop_front();
}

void files::function10(list &list) {
    std::cout << "Введите число, которое хотите добавить в список" << std::endl;
    int n;
    std::cin >> n;
    std::cout << "Введите номер элемента, которое хотите заменить" << std::endl;
    int k;
    std::cin >> k;
    list.insert(k, n);
    list.earse(k);
}

void files::function11(list &list) {
    if (list.getHead() == NULL) std::cout << "Список пуст" << std::endl;
    else std::cout << "Список не пуст" << std::endl;
}

void files::function12(list& list) {
    StrL *curr, *next, *prev;
    prev = list.getHead();
    list.setHead(list.getTail());
    curr = prev->getNext();
    while (curr != NULL) {
        next = curr->getNext();
        curr->setNext(prev);
        prev = curr;
        curr = next;
    }
    list.setHead(list.getTail());
}

void files::function13(list& lst){
    std::cout << "Введите номер элемента, после которого хотите вставить список" << std::endl;
    int k;
    std::cin >> k;
    list newList = inputNewList();
    StrL* node = lst.getAt(k);
    newList.getTail()->setNext(node->getNext());
    node->setNext(newList.getHead());
}

void files::function14(list& lst){
    list newList = inputNewList();
    lst.getTail()->setNext(newList.getHead());
    lst.setTail(newList.getTail());
}

void files::function15(list& lst){
    list newList = inputNewList();
    newList.getTail()->setNext(lst.getHead());
    lst.setHead(newList.getHead());
}

void files::result() {
    list lst;
    this->readIn(lst);
    std::cout << "Ниже представлен список функций, с которыми работает данная программа: /n1\tдобавление в конец списка\n"
                 "\t2\tдобавление в начало списка\n"
                 "\t3\tудаление последнего элемента\n"
                 "\t4\tудаление первого элемента\n"
                 "\t5\tдобавление элемента по индексу (вставка перед элементом, который был ранее доступен по этому индексу)\n"
                 "\t6\tполучение элемента по индексу\n"
                 "\t7\tудаление элемента по индексу\n"
                 "\t8\tполучение размера списка\n"
                 "\t9\tудаление всех элементов списка\n"
                 "\t10\tзамена элемента по индексу на передаваемый элемент\n"
                 "\t11\tпроверка на пустоту списка\n"
                 "\t12\tменяет порядок элементов в списке на обратный\n"
                 "\t13\tвставка другого списка в список, начиная с индекса\n"
                 "\t14\tвставка другого списка в конец\n"
                 "\t15\tвставка другого списка в начало\n"
                 "\t16\tпроверка на содержание другого списка в списке, можно сделать целочисленного типа\n"
                 "\t17\tпоиск первого вхождения другого списка в список\n"
                 "\t18\tпоиск последнего вхождения другого списка в список\n"
                 "\t19\tобмен двух элементов списка по индексам\n"
                 "\t20\tвыход из программы\n"
                 "Введите номер программы ";
    int numOfOperation;
    std::cin >> numOfOperation;
    while (numOfOperation != 20){
        std::cout << "Была выбрана функция: ";
        switch (numOfOperation) {
            case(1):
                fuction1(lst);
                printList(lst);
                break;
            case(2):
                fuction2(lst);
                printList(lst);
                break;
            case(3):
                printList(lst);
                break;
            case(4):
                printList(lst);
                break;
            case(5):
                printList(lst);
                break;
            case(6):
                std::cout << "Было получено значение:" << function6(lst) << std::endl;
                printList(lst);
                break;
            case(7):
                printList(lst);
                break;
            case(8):
                std::cout << "Было получено значение:" << function8(lst) << std::endl;
                printList(lst);
                break;
            case(9):
                std::cout << "Список пуст" << std::endl;
                break;
            case(10):
                printList(lst);
                break;
            case(11):
                function11(lst);
                break;
            case(12):
                printList(lst);
                break;
            case(13):
                printList(lst);
                break;
            case(14):
                printList(lst);
                break;
            case(15):
                printList(lst);
                break;
            case(16):
                printList(lst);
                break;
            case(17):
                printList(lst);
                break;
            case(18):
                printList(lst);
                break;
            case(19):
                printList(lst);
                break;
            default:
                std::cout << "Конечный список:" << std::endl;
                for (StrL *node = lst.getHead(); node != nullptr; node = node->getNext()) {
                    this->out << node->getData() << " ";
                }
                this->out << std::endl;
                std::cout << "выход из программы.\n";
                break;
        }
        std::cout << "Введите номер программы ";
        std::cin >> numOfOperation;
    }
}