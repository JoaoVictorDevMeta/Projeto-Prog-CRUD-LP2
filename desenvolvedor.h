#pragma once
#include <iostream>
#include <string>

class Desenvolvedor{
    private:
        std::string nome;
        std::string paisOrigem;
    public:
        Desenvolvedor( std::string nome, std::string paisOrigem){
            this->nome = nome;
            this->paisOrigem = paisOrigem;
        }

        void setNome(std::string n){
            nome = n;
        }

        void setPaisOrigem(std::string p){
            paisOrigem = p;
        }

        std::string getNome(){
            return nome;
        }

        std::string getPaisOrigem(){
            return paisOrigem;
        }


        void exibirInfo(){
            std::cout << "Informações do(a) desenvolvedor(a):" << std::endl;
            std::cout << "Nome: " << nome << std::endl;
            std::cout << "Pais de Origem: " << paisOrigem << std::endl;
        }
};