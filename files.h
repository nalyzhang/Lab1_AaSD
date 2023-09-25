#include <fstream>
#include "StrL.h"
#include "list.h"

class files {

public:

    std::ifstream inList;
    std::ifstream inL;
    std::ofstream outList;

    explicit files(const char in[] = "inL.txt", const char ouT[] = "outList.txt", const char w[] = "inList.txt") {
        this->inL.open(in);
        this->outList.open(ouT);
        this->inList.open(w);
    }

    ~files() {
        this->inL.close();
        this->outList.close();
        this->inList.close();
    }

    void result();

    void readIn(list& list);

    list inputNewList();

    void function1(list &list);

    void function2(list &list);

    void function3(list &list);

    void function4(list &list);

    void function5(list &list);

    int function6(list &list);

    void function7(list &list);

    int function8(list &list);

    void function9(list &list);

    void function10(list &list);

    void function11(list &list);

    void function12(list &list);

    void function13(list &list);

    void function14(list &lst);

    void function15(list &lst);

    void function19(list &lst);

    void function18(list &lst);

    void function17(list &lst);

    void function16(list &lst);
};
