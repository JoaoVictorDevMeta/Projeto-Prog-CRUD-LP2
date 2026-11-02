#pragma once
#include <iostream>
#include <string>
#include "jogo.h"

class JogoAAA : public Jogo {
private:
    float orcamentoMarketing;
    int qtdEstudios;

public:
    JogoAAA(int id, std::string titulo, float precoBase, int ano, Engine eng, Desenvolvedor dev, 
            float orcamentoMarketing, int qtdEstudios) 
        : Jogo(id, titulo, precoBase, ano, eng, dev) 
    {
        this->orcamentoMarketing = orcamentoMarketing;
        this->qtdEstudios = qtdEstudios;
    }

    float calcularPrecoFinal() override {
        int idade = 2026 - anoLancamento; // NOTA: utilizando ano fixo
        float descontoIdade = (idade * 0.05f);
        if (descontoIdade > 0.50f) descontoIdade = 0.50f; 

        float precoComMarketing = precoBase + (orcamentoMarketing / 1000);
        
        return precoComMarketing * (1.0f - descontoIdade);
    }

    void exibirInfo() {
        Jogo::exibirInfo(); 
        std::cout << "Tipo: AAA | Estúdios: " << qtdEstudios << " | Marketing: R$ " << orcamentoMarketing << std::endl;
        std::cout << "Preço Final: R$ " << calcularPrecoFinal() << std::endl << "-----------------------" << std::endl;
    }

    float getOrcamentoMarketing(){
        return orcamentoMarketing;
    }

    int getQtdEstudios(){
        return qtdEstudios;
    }
};