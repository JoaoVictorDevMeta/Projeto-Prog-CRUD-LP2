#include <iostream>
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

    float calcularPrecoFinal() {
        return getPrecoBase() + orcamentoMarketing;
    }

    void exibirInfo() {
        Jogo::exibirInfo(); 
        std::cout << "Tipo: AAA | Estúdios: " << qtdEstudios << " | Marketing: R$ " << orcamentoMarketing << std::endl;
        std::cout << "Preço Final: R$ " << calcularPrecoFinal() << "\n-----------------------" << std::endl;
    }
};