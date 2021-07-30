#include "montador.h"


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

std::string left_trim(const std::string &str) {
    return std::regex_replace(str, std::regex("^\\s+"), std::string(""));
}

std::string right_trim(const std::string &str) {
    return std::regex_replace(str, std::regex("\\s+$"), std::string(""));
}

std::string trim(const std::string &str) {
    return right_trim(left_trim(str));
}


std::vector<Infos> conversionTable = {
    {0,   "HALT",     NOARG,      NOARG},
    {1,   "LOAD",     REG,        MEM},
    {2,   "STORE",    REG,        MEM},
    {3,   "READ",     REG,        NOARG},
    {4,   "WRITE",    REG,        NOARG},
    {5,   "COPY",     REG,        NOARG},
    {6,   "PUSH",     REG,        NOARG},
    {7,   "POP",      REG,        NOARG},
    {8,   "ADD",      REG,        REG},
    {9,   "SUB",      REG,        REG},
    {10,  "MUL",      REG,        REG},
    {11,  "DIV",      REG,        REG},
    {12,  "MOD",      REG,        REG},
    {13,  "AND",      REG,        REG},
    {14,  "OR",       REG,        REG},
    {15,  "NOT",      REG,        NOARG},
    {16,  "JUMP",     MEM,        NOARG},
    {17,  "JZ",       MEM,        NOARG},
    {18,  "JN",       MEM,        NOARG},
    {19,  "CALL",     MEM,        NOARG},
    {20,  "RET",      NOARG,      NOARG}
};


Assembler::Assembler(std::string fileName){
    this->fileName = fileName;
}


void Assembler::getInstructionsFromFile() {
    std::string line;
    std::fstream myFile;

    myFile.open(this->fileName);

    if (myFile.is_open()) {
        while (getline (myFile,line) ) {
            std::stringstream ss(line);
            std::string item;
            while (getline(ss, item, ' ')) {
                
                if (item[0] == ';' || (!isalpha(item[0]) && !std::isdigit(item[0]))) break;
                this->fileInstructions.push_back(item);

            }
        }
        myFile.close();
    }

    else error("could not open file ! =x"); 
}


Infos Assembler::findInstructionBySymbol(std::string symbol) {
    for (auto info : conversionTable) {
        if (info.symbol == symbol) return info;
    }

    return Infos(-1, "NOT_FOUND", -1, -1);
}


int Assembler::getReg(std::string reg){
    if (reg == "R0") return 0;
    else if (reg == "R1") return 1;
    else if (reg == "R2") return 2;
    else if (reg == "R3") return 3;
    else return -1;
}



void Assembler::run(){
    this->getInstructionsFromFile();

    this->compiledInstructions = "";

    for (size_t i=0; i<this->fileInstructions.size(); i++){

        std::string str = this->fileInstructions[i];

        if (str == "END") break;
        
        if (str == "WORD") {
            i++;
            this->compiledInstructions += this->fileInstructions[i] + " ";
            continue;
        }

        Infos info = this->findInstructionBySymbol(str);

        if (info.code != -1) {
            this->compiledInstructions += std::to_string(info.code) + " ";

            if (info.arg1 != NOARG) {
                i++;
                if (info.arg1 == MEM) {
                    
                    int pos = 0;

                    for (size_t j=0; j<this->fileInstructions.size(); j++) {
                        std::string mem = this->fileInstructions[i] + ":";
                        std::string mempos = this->fileInstructions[j];
                        if (mem == mempos) {
                            pos = j - i - 1;
                        }
                    }

                    this->compiledInstructions += std::to_string(pos) + " ";

                } else if (info.arg1 == REG) {
                    
                    int reg = this->getReg(this->fileInstructions[i]);
                    
                    this->compiledInstructions += std::to_string(reg) + " ";

                }
            }
            if (info.arg2 != NOARG) {
                i++;
                if(info.arg2 == MEM) {
                    
                    int pos = 0;

                    for (size_t j=0; j<this->fileInstructions.size(); j++) {
                        std::string mem = this->fileInstructions[i] + ":";
                        std::string mempos = this->fileInstructions[j];
                        if (mem == mempos) {
                            pos = j - i - 1;
                        }
                    }

                    this->compiledInstructions += std::to_string(pos) + " ";


                } else if (info.arg2 == REG) {
                    
                    int reg = this->getReg(this->fileInstructions[i]);
                    
                    this->compiledInstructions += std::to_string(reg) + " ";

                }
            }
        }

   }

   std::cout << trim(this->compiledInstructions) << std::endl;
}


