#pragma once
#include <iostream>
#include <string>
#include "engine.h"
#include "desenvolvedor.h"

class Jogo {
    protected: 
        int id;
        std::string titulo;
        float precoBase;
        int anoLancamento;
        Engine eng;
        Desenvolvedor dev;
        int copiasVendidas;

    public:
        static int qtdJogosTotal;
        static int downloadsTotais;
        static float ganhosTotais;

        Jogo(int id, std::string titulo, float precoBase, int ano, Engine eng, Desenvolvedor dev) 
            : id(id), titulo(titulo), precoBase(precoBase), anoLancamento(ano), eng(eng), dev(dev) 
        {
            copiasVendidas = 0;
            qtdJogosTotal++;
        }

        virtual ~Jogo() {}

        int getId() { 
            return id; 
        }
        std::string getTitulo() {
            return titulo;
        }
        float getPrecoBase() { 
            return precoBase; 
        }
        int getAnoLancamento() { 
            return anoLancamento; 
        }
        Engine getEng() { 
            return eng; 
        }       
        Desenvolvedor getDev() { 
            return dev; 
        }  
        int getCopiasVendidas(){
            return copiasVendidas;;
        }

        void setId(int id) { 
            this->id = id; 
        }
        void setTitulo(std::string n) { 
            titulo = n; 
        } 
        void setPrecoBase(float p) { 
            precoBase = p;
        }
        void setAnoLancamento(int a) {
            anoLancamento = a; 
        }
        void setEng(Engine e) { 
            eng = e; 
        }
        void setDev(Desenvolvedor d) { 
            dev = d; 
        }
        void adicionarCopiasVendidas(int q){
            copiasVendidas += q;
        }

        virtual void exibirInfo() {
            std::cout << "ID: " << id << " | " << titulo << " (" << anoLancamento << ")" << std::endl;
            std::cout << "Desenvolvedora: " << dev.getNome() << " | Engine: " << eng.getNome() << std::endl;
        }

        virtual float calcularPrecoFinal() {
            return precoBase; 
        }
};

int Jogo::qtdJogosTotal = 0;
int Jogo::downloadsTotais = 0;
float Jogo::ganhosTotais = 0.0f;