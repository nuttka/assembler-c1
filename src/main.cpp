#include <iostream>

#include "montador.h"
#include <memory>



#define error(msg) { std::cout << "eRRor: " << msg << std::endl; exit(EXIT_FAILURE); }


int main(int argc, char *argv[]) {
    if (argc != 2) {
        error("1 arg - no file");
    }

    const std::string fileName = std::string(argv[1]);

    Assembler *assembler = new Assembler(fileName);
    assembler->run();

    return 0;
}