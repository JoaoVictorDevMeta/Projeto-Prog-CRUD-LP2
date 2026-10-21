#include <iostream>
#include <string.h>

class Engine{
    private:
        std::string nome;
        std::string linguagemBase;
        std::string autoria;
    public:
        Engine(std::string nome, std::string linguagemBase, std::string autoria){
            this->nome = nome;
            this->linguagemBase = linguagemBase;
            this->autoria = autoria;
        }
};