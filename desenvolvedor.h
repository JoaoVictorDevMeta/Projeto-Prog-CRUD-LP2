#pragma once
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

        void setNome(std::string n){
            nome = n;
        }

        void setPaisOrigem(std::string p){
            paisOrigem = p;
        }

        void setAnoFundacao(int a){
            anoFundacao = a;
        }

        std::string getNome(){
            return nome;
        }

        std::string getPaisOrigem(){
            return paisOrigem;
        }

        int getAnoFundacao(){
            return anoFundacao;
        }

        void exibirInfo(){
            std::cout << "Informações do(a) desenvolvedor(a):" << std::endl;
            std::cout << "Nome: " << nome << std::endl;
            std::cout << "Pais de Origem: " << paisOrigem << std::endl;
            std::cout << "Ano de Fundação: " << anoFundacao << std::endl << std::endl;
        }
};