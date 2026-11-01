#pragma once
#include <iostream>
#include <string> 
#include <cstdlib>
#include <vector>
#include "engine.h"
#include "desenvolvedor.h"
#include "jogo.h"
#include "jogoIndie.h"
#include "jogoAAA.h"
#include "jogoMobile.h"

std::string traco = "-----------------------------";

class VaporStudio {
    private:
        std::vector<Jogo*> catalogoJogos;
    
    public:
        void menu(){
            std::cout << traco << std::endl;
            std::cout << "Menu" << std::endl;
            std::cout << traco << std::endl;
            std::cout << "Digite o número para executar sua operação" << std::endl;
            

            std::cout << "0 - Sair" << std::endl;

        }   

        void inserirJogo(){
            std::cout << traco << std::endl;
            std::cout << "Inserir Jogo" << std::endl;
            std::cout << traco << std::endl;

            int id = 0;

            std::cout << "Nome do jogo: ";
            std::cin.ignore();
            std::string nm;
            std::getline(std::cin, nm);

            std::cout << "Preço base: ";
            float preco;
            std::cin >> preco;

            std::cout << "Ano de lançamento: ";
            int ano;
            std::cin >> ano;

            std::cout << "\nEscolha a Engine:\n";
            std::cout << "1. Unreal Engine 5 (C++)\n";
            std::cout << "2. Unity (C#)\n";
            std::cout << "3. Godot (GDScript/C++)\n";
            std::cout << "4. Engine própria (Digitar)\n";
            std::cout << "Opção: ";

            int opEngine;
            std::cin >> opEngine;
            Engine eng("", "");
            if(opEngine == 1) {
                eng = Engine("Unreal Engine 5", "C++");
            }else if(opEngine == 2) {
                eng = Engine("Unity", "C#");
            }else if(opEngine == 3){
                eng = Engine("Godot", "GDScript");
            } else {
                std::cout << "Nome da Engine: ";
                std::string nomeEng;
                std::cin >> nomeEng;
                std::cout << "Linguagem base: ";
                std::string langEng;
                std::cin >> langEng;
                eng = Engine(nomeEng, langEng);
            }

            std::cout << "\n--- Dados da Desenvolvedora ---\n";
            std::cout << "Nome da desenvolvedora: ";
            std::cin.ignore();
            std::string nomeDev;
            std::getline(std::cin, nomeDev);
            
            std::cout << "País de origem: ";
            std::string paisDev;
            std::getline(std::cin, paisDev);

            Desenvolvedor dev(nomeDev, paisDev);

            std::cout << "\nTipo (1 - AAA | 2 - Indie | 3 - Mobile): ";
            int tipoJogo;
            std::cin >> tipoJogo;

            if(tipoJogo == 1) {
                std::cout << "Orçamento do marketing: R$ ";
                float marketing;
                std::cin >> marketing;
                std::cout << "Quantidade de estúdios envolvidos: ";
                int qtdE;
                std::cin >> qtdE;
            
                catalogoJogos.push_back(new JogoAAA(
                    id, nm, preco, ano, eng, dev, marketing, qtdE
                ));
            }else if(tipoJogo == 2){
                std::cout << "Nome do desenvolvedor principal: ";
                std::cin.ignore();
                std::string devPrincipal;
                std::getline(std::cin, devPrincipal);
                std::cout << "Possui publisher? (1 - Sim / 0 - Não): ";
                bool publisher;
                std::cin >> publisher;

                catalogoJogos.push_back(new JogoIndie(
                    id, nm, preco, ano, eng, dev, devPrincipal, publisher
                ));
            } else {
                std::cout << "Possui anúncios? (1 - Sim / 0 - Não): ";
                bool anuncios;
                std::cin >> anuncios;

                catalogoJogos.push_back(new JogoMobile(
                    id, nm, preco, ano, eng, dev, anuncios
                ));
            }

            std::cout << "\nJogo cadastrado com sucesso!\n";
        }   

        void listarJogos(){
            std::cout << traco << std::endl;
            std::cout << "Listando Jogos (" << Jogo::qtdJogosTotal <<  ")" << std::endl;
            std::cout << traco << std::endl;

            if(catalogoJogos.empty()){
                std::cout << "O catálogo está vazio.\n";
                return;
            }

            for (size_t i = 0; i < catalogoJogos.size(); i++) {
                catalogoJogos[i]->exibirInfo();
                std::cout << std::endl;
            }
        }


};