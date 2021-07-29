#ifndef MONTADOR_H
#define MONTADOR_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>



#define error(msg) { std::cout << "eRRor: " << msg << std::endl; exit(EXIT_FAILURE); }


#define NOARG -1
#define REG 0
#define MEM 1



struct Infos {
    int code;
    std::string symbol;
    int arg1;
    int arg2;
    int size;
    Infos(int code, std::string symbol, int arg1, int arg2, int size){
        this->code = code;
        this->symbol = symbol;
        this->arg1 = arg1;
        this->arg2 = arg2;
        this->size = size;
    }
};


// struct Operation {
//     std::string label;
//     std::string oper;
//     std::string operator1;
//     std::string operator2;
// };



class Assembler {
    private:
        std::string fileName;
        std::vector<std::string> fileInstructions;
        std::string compiledInstructions;

    public:
        Assembler(std::string);
        ~Assembler();

        // void fileInstructionsTreatment();
        Infos findInstructionBySymbol(std::string);
        // std::vector<Operation> get_operations();
        void getInstructionsFromFile();
        int getReg(std::string);
        // void add_operation(Operation);
        // void convert(std::vector<std::string>);
        void run();
};


#endif
