#include <iostream>
#include <string.h>

class Desenvolvedor{
    private:
        std::string nome;
        std::string paisOrigem;
        int anoFundacao;
    public:
        Desenvolvedor( std::string nome, std::string paisOrigem, int anoFundacao){
            this->nome = nome;
            this->paisOrigem = paisOrigem;
            this->anoFundacao = anoFundacao;
        }
};