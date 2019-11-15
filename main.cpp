#include <iostream>
#include "Tries.h"
int main() {
    Tries U;
    U.insert("fi");
    U.insert("fa");
    U.insert("foo");
    U.insert("fifo");
    std::cout << "Se encontro : " << U.search_by_complete("fif") << std::endl;

    return 0;
}