#include "montador.h"

std::vector<Infos> conversionTable = {
    {"0",   "HALT",     "0"},
    {"1",   "LOAD",     "2"},
    {"2",   "STORE",    "2"},
    {"3",   "READ",     "1"},
    {"4",   "WRITE",    "1"},
    {"5",   "COPY",     "2"},
    {"6",   "PUSH",     "1"},
    {"7",   "POP",      "1"},
    {"8",   "ADD",      "2"},
    {"9",   "SUB",      "2"},
    {"10",  "MUL",      "2"},
    {"11",  "DIV",      "2"},
    {"12",  "MOD",      "2"},
    {"13",  "AND",      "2"},
    {"14",  "OR",       "2"},
    {"15",  "NOT",      "1"},
    {"16",  "JUMP",     "1"},
    {"17",  "JZ",       "1"},
    {"18",  "JN",       "1"},
    {"19",  "CALL",     "1"},
    {"20",  "RET",      "0"},
};


Assembler::Assembler(std::string fileName){
    this->fileName = fileName;
}


void split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

void Assembler::run(){
    std::string line;
    std::fstream myFile;

    myFile.open(this->fileName);

    // while (myFile >> word) {
    //     // displaying content
    //     std::cout << word << std::endl;
    // }

    if (myFile.is_open()) {
        while ( getline (myFile,line) ){
            bool nextLine = false;

            // std::cout << line << std::endl;

            std::stringstream ss(line);
            std::string item;
            while (getline(ss, item, ' ')) {
                if(item[0] == ';' || item[0] == ' ') break;
                std::cout << item << std::endl;
            }


            // if(nextLine) break;
            
        }
        myFile.close();
    }

    else error("could not open file ! =x"); 
}




std::vector<Operation> Assembler::get_operations() {
    return this->operations;
}
void Assembler::add_operation(Operation operation) {
    this->operations.push_back(operation);
}

void Assembler::convert(std::vector<std::string>) {
    std::cout << "=~~/";
}