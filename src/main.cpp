#include <iostream>
#include <memory>

#include "montador.h"
#include <memory>



int main(int argc, char *argv[]) {
    if (argc != 2) {
        error("1 arg - no file");
    }

    const std::string fileName = std::string(argv[1]);
    
    Assembler *assembler = new Assembler(fileName);
    assembler->run();

    return 0;
}