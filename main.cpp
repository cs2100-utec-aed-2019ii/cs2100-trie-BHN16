#include <iostream>
#include "Tries.h"
int main() {
    Tries U;
    U.insert("fi");
    U.insert("fa");
    U.insert("foo");
    U.insert("fifo");
    std::cout << "Se encontro : " << U.search_by_complete("fif") << std::endl;
    U.erase("fa");
    U.erase("fifo");
    std::cout << "Se encontro : " << U.search_by_prefix("f") << std::endl;
    std::cout << "Se encontro : " << U.search_by_complete("fa") << std::endl;
    std::cout << "Se encontro : " << U.search_by_complete("fifo") << std::endl;
    U.insert("hola");
    U.print();
    return 0;
}
