#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "jogo.h"

class JogoIndie : public Jogo {
    private:
        std::string nomeDesenvolvedor;
        bool temPublisher;
    public:
        JogoIndie(int id, std::string titulo, float precoBase, int ano, Engine eng, Desenvolvedor dev
        , std::string nomeD, bool temP) 
        : Jogo(id, titulo, precoBase, ano, eng, dev) {
            this->nomeDesenvolvedor = nomeD;
            this->temPublisher = temP;
        }
        float calcularPrecoFinal(){
            float preco = precoBase;
            if(temPublisher){
                preco *= 1.3;
            }
            //sugestão para num de downloads
            if(copiasVendidas > 100) {
                preco *= 0.85;
            }
            return preco;
        }

        void exibirInfo() {
            Jogo::exibirInfo(); 
            std::cout << "Tipo: Indie | Desenvolvedor Principal: " << nomeDesenvolvedor << std::endl;
            std::cout << "Preço Final: R$ " << std::fixed << std::setprecision(2) << calcularPrecoFinal() << std::endl << "-----------------------" << std::endl;
        }

        std::string getNomeDesenvolvedor(){
            return nomeDesenvolvedor;
        }

        bool getTemPublisher(){
            return temPublisher; 
        }
};