#include <fstream>
#include "StrL.h"
#include "list.h"

class files {

public:

    std::ifstream inL;
    std::ifstream in;
    std::ofstream out;

    explicit files(const char in[] = "inL.txt", const char ouT[] = "out.txt", const char w[] = "in.txt") {
        this->inL.open(in);
        this->out.open(ouT);
        this->in.open(w);
    }

    ~files() {
        this->inL.close();
        this->out.close();
        this->in.close();
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
};

#endif
