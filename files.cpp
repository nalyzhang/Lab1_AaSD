#include "files.h"
#include <iostream>

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
    if (this->inList.is_open() == 1) {
        int node;
        if (this->inList.eof() == 0) {
            while(this->inList.eof() == 0) {
                this->inList >> node;
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

void files::function1(list& list){
    std::cout << "\n\t1\tдобавление в конец списка\n"
                 "Введите число, которое хотите добавить в список" << std::endl;
    int n;
    std::cin >> n;
    list.push_back(n);
}

void files::function2(list &list) {
    std::cout << "\t2\tдобавление в начало списка\n";
    std::cout << "Введите число, которое хотите добавить в список" << std::endl;
    int n;
    std::cin >> n;
    list.push_front(n);
}

void files::function3(list &list) {
    std::cout << "\t3\tудаление последнего элемента\n";
    list.pop_back();
}

void files::function4(list& list) {
    std::cout << "\t4\tудаление первого элемента\n";
    list.pop_front();
}

void files::function5(list& list) {
    std::cout << "\t5\tдобавление элемента по индексу (вставка перед элементом, который был ранее доступен по этому индексу)\n";
    std::cout << "Введите число, которое хотите добавить в список" << std::endl;
    int n;
    std::cin >> n;
    std::cout << "Введите номер элемента, перед которым хотите вставить число" << std::endl;
    int k;
    std::cin >> k;
    list.insert(k - 1, n);
}

int files::function6(list& list) {
    std::cout << "\t6\tполучение элемента по индексу\n";
    std::cout << "Введите номер элемента, чье значение хотите получить" << std::endl;
    int k;
    std::cin >> k;
    StrL* node = list.getAt(k);
    return node->getData();
}

void files::function7(list& list) {
    std::cout << "\t7\tудаление элемента по индексу\n";
    std::cout << "Введите номер элемента, который хотите удалить" << std::endl;
    int k;
    std::cin >> k;
    list.earse(k);
}

int files::function8(list &list) {
    std::cout << "\t8\tполучение размера списка\n";
    int count;
    for (StrL* node = list.head; node != NULL; node = node->next)
        ++count;
    return count;
}

void files::function9(list &list) {
    std::cout << "\t9\tудаление всех элементов списка\n";
    while(list.head != NULL) list.pop_front();
}

void files::function10(list &list) {
    std::cout << "\t10\tзамена элемента по индексу на передаваемый элемент\n"
                 "Введите число, которое хотите добавить в список" << std::endl;
    int n;
    std::cin >> n;
    std::cout << "Введите номер элемента, которое хотите заменить" << std::endl;
    int k;
    std::cin >> k;
    list.insert(k, n);
    list.earse(k);
}

void files::function11(list &list) {
    std::cout << "\t11\tпроверка на пустоту списка\n";
    if (list.head == NULL) std::cout << "Список пуст" << std::endl;
    else std::cout << "Список не пуст" << std::endl;
}

void files::function12(list& list) {
    //todo: переделать функцию
    std::cout << "\t12\tменяет порядок элементов в списке на обратный\n";
    StrL *curr, *next, *prev = NULL;
    list.tail = list.head;
    curr = list.head;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    list.head = prev;
}

void files::function13(list& lst, list newList){
    std::cout << "\t13\tвставка другого списка в список, начиная с индекса\n"
                 "Введите номер элемента, после которого хотите вставить список" << std::endl;
    int k;
    std::cin >> k;
    if (k > function8(lst) || k < 0) {
        std::cout << "Элемента с таким индексом не существует" << std::endl;
        return;
    }
    if (newList.head == NULL) {
        std::cout << "Ввдеденный список пуст";
        return;
    }

    int i = 0;
    for (StrL* node = newList.head; node!= NULL; node = node->next) lst.insert(k+i++, node->data);
}

void files::function14(list& lst, list newList){
    std::cout << "\t14\tвставка другого списка в конец\n";
    for (StrL* node = newList.head; node!= NULL; node = node->next) lst.push_back(node->data);
}

void files::function15(list& lst, list newList){
    std::cout << "\t15\tвставка другого списка в начало\n";
    int i = -1;
    for (StrL* node = newList.head; node!= NULL; node = node->next) lst.insert(i++, node->data);
}

void files::function16(list& lst, list newList){
    std::cout << "\t16\tпроверка на содержание другого списка в списке, можно сделать целочисленного типа\n";
    StrL* curr = newList.head;
    int count = 0, lenNewList = function8(newList), lenList = function8(lst);
    if (lenList < lenNewList) {
        std::cout << "Заданный список не может входить в данный в силу большего размера" << std::endl;
        return;
    }
    for (StrL* node = lst.head; node != nullptr; node = node->next){
        if (curr == nullptr)
        {
            std::cout << "Список входит в данный" << std::endl;
            return;
        }
        if (curr->data == node->data) {
            count++;
            curr = curr->next;
        }
        else {
            if (count == lenNewList) {
                std::cout << "Список входит в данный" << std::endl;
                return;
            }
            else {
                count = 0;
                curr = newList.head;
            }
        }
    }
    std::cout << "Список не входит в данный" << std::endl;
}

void files::function17(list& lst, list newList) {
    std::cout << "\t17\tпоиск первого вхождения другого списка в список\n";
    StrL *curr = newList.head;
    int count = 0, lenNewList = function8(newList), lenList = function8(lst), n = -1, i = 0;
    bool flag = true;
    if (lenList < lenNewList) {
        std::cout << "Заданный список не может входить в данный в силу большего размера" << std::endl;
        return;
    }
    for (StrL *node = lst.head; node != nullptr; node = node->next) {
        if (curr == nullptr) {
            std::cout << "Первое вхождение списка в данный начинается с индекса " << n << std::endl;
            return;
        }
        if (curr->data == node->data) {
            if (flag) {
                n = i;
                flag = false;
            }
            count++;
            curr = curr->next;
        } else {
            if (count == lenNewList) {
                std::cout << "Первое вхождение списка в данный начинается с индекса " << n << std::endl;
                return;
            } else {
                count = 0;
                curr = newList.head;
                flag = true;
            }
        }
        i++;
    }
    std::cout << "Список не входит в данный" << std::endl;
}

void files::function18(list& lst, list newList){
    std::cout << "\t18\tпоиск последнего вхождения другого списка в список\n";
    StrL *curr = newList.head;
    int count = 0, lenNewList = function8(newList), lenList = function8(lst), n = -1, i = 0;
    bool flag = true;
    if (lenList < lenNewList) {
        std::cout << "Заданный список не может входить в данный в силу большего размера" << std::endl;
        return;
    }
    for (StrL *node = lst.head; node != nullptr; node = node->next) {
        i++;
        if (curr == nullptr || (curr->data != node->data)) {
            count = 0;
            curr = newList.head;
            flag = true;
            continue;
        }
        if (curr->data == node->data) {
            if (flag) {
                n = i-1;
                flag = false;
            }
            count++;
            curr = curr->next;
        }
    }
    if (n >= 0) std::cout << "Последнее вхождение списка в данный начинается с индекса " << n << std::endl;
    else std::cout << "Список не входит в данный" << std::endl;
}

void files::function19(list& lst){
    int first, second;
    std::cout << "\t19\tобмен двух элементов списка по индексам\n"
                 "Введите номер первого элемента:" << std::endl;
    std::cin >> first;
    std::cout << "Введите номер второго элемента: " << std::endl;
    std::cin >> second;
    StrL *firstNode, *secondNode;
    firstNode = lst.getAt(first);
    secondNode = lst.getAt(second);
    if (firstNode != NULL && secondNode != NULL) {
        int tmp = firstNode->data;
        firstNode->data = secondNode->data;
        secondNode->data = tmp;
    }
}

void files::result() {
    list lst, newList;
    this->readIn(lst);
    newList = this->inputNewList();
    std::cout << "Список:";
    for (StrL *node = lst.head; node != nullptr; node = node->next) {
        std::cout << node->getData() << " ";
    }
    std::cout << "\n";
    std::cout << "Ниже представлен список функций, с которыми работает данная программа:"
                 "\n\t1\tдобавление в конец списка\n"
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
        unsigned int start_time =  clock(); // начальное время
        switch (numOfOperation) {
            case(1):
                function1(lst);
                break;
            case(2):
                function2(lst);
                break;
            case(3):
                function3(lst);
                break;
            case(4):
                function4(lst);
                break;
            case(5):
                function5(lst);
                break;
            case(6):
            {
                auto count = function6(lst);
                std::cout << "Было получено значение: " << count << std::endl;
            }
                break;
            case (7):
                function7(lst);
                break;
            case(8):
            {
                auto count = function8(lst);
                std::cout << "Было получено значение: " << count << std::endl;
            }
                break;
            case(9):
                function9(lst);
                std::cout << "Список пуст" << std::endl;
                break;
            case(10):
                function10(lst);
                break;
            case(11):
                function11(lst);
                break;
            case(12):
                function12(lst);
                break;
            case(13):
                function13(lst, newList);
                break;
            case(14):
                function14(lst, newList);
                break;
            case(15):
                function15(lst, newList);
                break;
            case(16):
                function16(lst, newList);
                break;
            case(17):
                function17(lst, newList);
                break;
            case(18):
                function18(lst, newList);
                break;
            case(19):
                function19(lst);
                break;
            case(20):
                std::cout << "Конечный список:" << std::endl;
                for (StrL *node = lst.head; node != nullptr; node = node->next) {
                    this->outList << node->getData() << " ";
                }
                this->outList << std::endl;
                std::cout << "выход из программы.\n";
                break;
            default:
                std::cout << "Функции с таким номером нет\n";
                break;
        }
        unsigned int end_time = clock(); // конечное время
        unsigned int search_time = end_time - start_time; // искомое время
        std::cout << "Время, затраченное на работу функции: " << search_time << std::endl;
        std::cout << "Полученный список:" << std::endl;
        if (lst.head != NULL) {
            for (StrL *node = lst.head; node != nullptr; node = node->next) {
                std::cout << node->getData() << " ";
            }
            std::cout << std::endl;
        } else std::cout << "Нет списка" << '\n';
        std::cout << "Введите номер программы ";
        std::cin >> numOfOperation;
    }
}
