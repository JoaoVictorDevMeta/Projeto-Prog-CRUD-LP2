#pragma once
#include <iostream>
#include <string>
#include "jogo.h"

class JogoMobile : public Jogo {
    private:
        bool possuiAnuncios;
    public:
        JogoMobile(int id, std::string titulo, float precoBase, int ano, Engine eng, Desenvolvedor dev
        , bool anun, int qtd) 
        : Jogo(id, titulo, precoBase, ano, eng, dev) {
            this->possuiAnuncios = anun;
        }
        float calcularPrecoFinal(){
            if(possuiAnuncios){
                return 0.0;
            }else {
                return precoBase;
                //sugestão de precificação baseado na quantidade de downloads
                //return (copiasVendidas > 100) ? precoBase * 0.5f : precoBase;
            }
        }
};