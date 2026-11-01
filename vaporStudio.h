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

        }
};