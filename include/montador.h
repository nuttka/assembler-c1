#ifndef MONTADOR_H
#define MONTADOR_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>



#define error(msg) { std::cout << "eRRor: " << msg << std::endl; exit(EXIT_FAILURE); }


struct Infos {
    std::string code;
    std::string symbol;
    std::string nextOperations;
};


struct Operation {
    std::string label;
    std::string oper;
    std::string operator1;
    std::string operator2;
};


class Assembler {
    private:
        std::vector<Operation> operations;
        std::string fileName;

    public:
        Assembler(std::string);
        ~Assembler();

        std::vector<Operation> get_operations();
        void add_operation(Operation);
        void convert(std::vector<std::string>);
        void run();
};


#endif
