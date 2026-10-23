#pragma once
#include <iostream>
#include <string.h>

class Engine{
    private:
        std::string nome;
        std::string linguagemBase;
    public:
        Engine(std::string nome, std::string linguagemBase){
            this->nome = nome;
            this->linguagemBase = linguagemBase;
        }

        std::string getNome(){
            return nome;
        }

        std::string getLinguagemBase(){
            return linguagemBase;
        }
};