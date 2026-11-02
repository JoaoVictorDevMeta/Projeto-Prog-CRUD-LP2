#pragma once
#include <iostream>
#include <string> 
#include <cstdlib>
#include <vector>
#include <fstream>
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
            system("cls");
            std::cout << "\n";
            std::cout << "  ##    ##  ######  ######   ######   ######  \n";
            std::cout << "  ##    ## ##    ## ##   ## ##    ## ##    ## \n";
            std::cout << "  ##    ## ######## ##   ## ##    ## ##    ## \n";
            std::cout << "   ##  ##  ##    ## ######  ##    ## ######   \n";
            std::cout << "    ## ##  ##    ## ##      ##    ## ##   ##  \n";
            std::cout << "     ###   ##    ## ##       ######  ##    ## \n";
            std::cout << "                  S T U D I O\n\n";
            std::cout << traco << std::endl;
            std::cout << "MENU PRINCIPAL" << std::endl;
            std::cout << traco << std::endl;
            std::cout << "Digite o número para executar sua operação" << std::endl;
            

            std::cout << "0 - Sair" << std::endl;
            std::cout << "1 - Cadastrar jogo" << std::endl;
            std::cout << "2 - Listar jogos" << std::endl;
            std::cout << "3 - Editar jogo" << std::endl;
            std::cout << "4 - Remover jogo" << std::endl;
            std::cout << "5 - Vender jogo" << std::endl;
            std::cout << "6 - Gerar relatório atual" << std::endl;
            std::cout << "7 - Mostrar informações de um jogo" << std::endl;
        }   

        void inserirJogo(){
            system("cls");
            std::cout << traco << std::endl;
            std::cout << "Inserir Jogo" << std::endl;
            std::cout << traco << std::endl;

            int id = Jogo::qtdJogosTotal;

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
            system("pause");
        }   

        void listarJogos(){
            system("cls");
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
            system("pause");
        }

        int pesquisar(std::string titulo) {
            std::vector<int> indicesEncontrados;

            for(size_t i = 0; i < catalogoJogos.size(); i++){
                if(catalogoJogos[i]->getTitulo().find(titulo) != std::string::npos){
                    indicesEncontrados.push_back(i);        
                }
            }

            if (indicesEncontrados.empty()) return -1;

            if (indicesEncontrados.size() == 1) {
                return indicesEncontrados[0];
            }

            std::cout << "Múltiplos jogos encontrados:\n";
            for (int idx : indicesEncontrados) {
                std::cout << "[" << idx << "] " << catalogoJogos[idx]->getTitulo() << "\n";
            }
            
            int escolha;
            std::cout << "Digite o índice desejado: ";
            std::cin >> escolha;
            return escolha;
        }

        void exibirUmJogo() {
            system("cls");
            std::cout << traco << std::endl;
            std::cout << "Exibir Detalhes do Jogo" << std::endl;
            std::cout << "Digite o nome do jogo: ";
            std::string nomeP;
            std::getline(std::cin >> std::ws, nomeP);

            int idJogo = pesquisar(nomeP);
            if (idJogo != -1) {
                std::cout << traco << std::endl;
                catalogoJogos[idJogo]->exibirInfo();
                std::cout << traco << std::endl;
            } else {
                std::cout << "Erro: Nenhum jogo encontrado com esse nome.\n";
            }
            system("pause");
        }

        void alterarJogo(){
            std::cout << traco << std::endl;
            std::cout << "Editar Jogo" << std::endl;
            std::cout << traco << std::endl;

            std::cout << "Digite o nome do jogo que \ndeseja editar.\n"; 
            std::cin.ignore();
            std::string nomeP;
            std::getline(std::cin, nomeP);

            int idJogo;
            idJogo = pesquisar(nomeP);
            if (idJogo == -1) {
                std::cout << "Erro: Nenhum jogo encontrado com esse nome.\n";
                return; 
            }

            std::cout << traco << std::endl;
            std::cout << "Editando o seguinte jogo:" << std::endl;
            catalogoJogos[idJogo]->exibirInfo();
            std::cout << traco << std::endl;

            std::string entrada;

            std::cout << "Nome do jogo [" << catalogoJogos[idJogo]->getTitulo() << "]: ";
            std::getline(std::cin, entrada);
            if (!entrada.empty()) {
                catalogoJogos[idJogo]->setTitulo(entrada);
            }

            std::cout << "Preço Base [" << catalogoJogos[idJogo]->getPrecoBase() << "]: ";
            std::getline(std::cin, entrada);
            if (!entrada.empty()) {
                catalogoJogos[idJogo]->setPrecoBase(std::stof(entrada));
            }

            std::cout << "Ano de Lançamento [" << catalogoJogos[idJogo]->getAnoLancamento() << "]: ";
            std::getline(std::cin, entrada);
            if (!entrada.empty()) {
                catalogoJogos[idJogo]->setAnoLancamento(std::stoi(entrada));
            }

            std::cout << "\nJogo atualizado com sucesso!\n";
            std::cout << traco << std::endl;
            catalogoJogos[idJogo]->exibirInfo();
            system("pause");
        }

        void removerJogo() {
            std::cout << traco << std::endl;
            std::cout << "Deletar Jogo" << std::endl;
            std::cout << traco << std::endl;

            std::cout << "Digite o nome do jogo que\n deseja deletar\n"; 
            std::cin.ignore();
            std::string nomeP;
            std::getline(std::cin, nomeP);

            int idJogo;
            idJogo = pesquisar(nomeP);
            if (idJogo == -1) {
                std::cout << "Erro: Nenhum jogo encontrado com esse nome.\n";
                return; 
            }

            std::cout << traco << std::endl;
            std::cout << "Jogo selecionado para remoção: " << std::endl;
            catalogoJogos[idJogo]->exibirInfo();
            std::cout << traco << std::endl;

            std::cout << "Tem a certeza absoluta que deseja remover este jogo? (1 - Sim / 0 - Nao): ";
            int confirmacao;
            std::cin >> confirmacao;
            
            if(confirmacao){
                delete catalogoJogos[idJogo];
                catalogoJogos.erase(catalogoJogos.begin() + idJogo);
                std::cout << "\nJogo removido com sucesso!\n";
            }else{
                std::cout << "\nOperação cancela\n";
            }
            system("pause");
        }

        void vender(){
            std::cout << traco << std::endl;
            std::cout << "Vender Jogo" << std::endl;
            std::cout << traco << std::endl;

            std::cout << "Digite o nome do jogo que\n deseja vender\n"; 
            std::cin.ignore();
            std::string nomeP;
            std::getline(std::cin, nomeP);

            int indexVetor = pesquisar(nomeP);
            
            if (indexVetor == -1) {
                std::cout << "Erro: Nenhum jogo encontrado com esse nome.\n";
                return; 
            }

            std::cout << "\nQuantidade da venda: \n";
            int qtd;
            std::cin >> qtd;

            Jogo* jogoVendido = catalogoJogos[indexVetor];
            
            float precoUnitario = jogoVendido->calcularPrecoFinal();
            float valorTotalDaVenda = precoUnitario * qtd;
            
            Jogo::ganhosTotais += valorTotalDaVenda;
            jogoVendido->adicionarCopiasVendidas(qtd);

            std::cout << "Venda realizada! Jogo: " << jogoVendido->getTitulo() 
            << " | Quantidade: " << qtd 
            << " | Total: R$ " << valorTotalDaVenda << std::endl;
            system("pause");
        }

        void gerarRelatorio() {
            system("cls");
            std::cout << traco << std::endl;
            std::cout << "Relatório Geral - VaporStudio" << std::endl;
            std::cout << traco << std::endl;

            std::cout << "Total de Jogos Cadastrados no Catálogo: " << catalogoJogos.size() << std::endl;
            std::cout << "Faturamento Total (Vendas): R$ " << Jogo::ganhosTotais << std::endl;

            if (catalogoJogos.empty()) {
                std::cout << "\nO catálogo está vazio. Não há mais dados para gerar.\n";
                std::cout << traco << std::endl;
                return;
            }

            float valorTotalBaseCatalogo = 0.0f;
            int totalCopias = 0;
            int qtdAAA = 0;
            int qtdIndie = 0;
            int qtdMobile = 0;

            for (Jogo* j : catalogoJogos) {
                valorTotalBaseCatalogo += j->getPrecoBase();
                totalCopias += j->getCopiasVendidas();

                if (dynamic_cast<JogoAAA*>(j) != nullptr) {
                    qtdAAA++;
                } 
                else if (dynamic_cast<JogoIndie*>(j) != nullptr) {
                    qtdIndie++;
                } 
                else if (dynamic_cast<JogoMobile*>(j) != nullptr) {
                    qtdMobile++;
                }
            }

            std::cout << "Soma do Preço Base de todos os jogos: R$ " << valorTotalBaseCatalogo << std::endl;
            std::cout << "Total de Cópias Vendidas (Volume): " << totalCopias << std::endl;
            
            std::cout << "\n--- Distribuição do Catálogo ---" << std::endl;
            std::cout << "Jogos AAA: " << qtdAAA << std::endl;
            std::cout << "Jogos Indie: " << qtdIndie << std::endl;
            std::cout << "Jogos Mobile: " << qtdMobile << std::endl;
            std::cout << traco << std::endl;
            system("pause");
        }

        void salvarArquivo () {
            std::ofstream lista("dados.txt");

            if (!lista.is_open()) {
                std::cout << "Erro ao abrir o lista para guardar os dados!\n";
                return;
            }

            lista << Jogo::ganhosTotais << "\n";
            lista << Jogo::downloadsTotais << "\n";

            for (Jogo* j : catalogoJogos) {
                if (JogoAAA* aaa = dynamic_cast<JogoAAA*>(j)) {
                    lista << "AAA\n";
                    lista << aaa->getId() << "\n";
                    lista << aaa->getTitulo() << "\n";
                    lista << aaa->getPrecoBase() << "\n";
                    lista << aaa->getAnoLancamento() << "\n";
                    lista << aaa->getEng().getNome() << "\n";
                    lista << aaa->getEng().getLinguagemBase() << "\n";
                    lista << aaa->getDev().getNome() << "\n";
                    lista << aaa->getDev().getPaisOrigem() << "\n";
                    
                    lista << aaa->getOrcamentoMarketing() << "\n";
                    lista << aaa->getQtdEstudios() << "\n";
                }
                else if (JogoIndie* indie = dynamic_cast<JogoIndie*>(j)) {
                    lista << "INDIE\n";
                    lista << indie->getId() << "\n";
                    lista << indie->getTitulo() << "\n";
                    lista << indie->getPrecoBase() << "\n";
                    lista << indie->getAnoLancamento() << "\n";
                    lista << indie->getEng().getNome() << "\n";
                    lista << indie->getEng().getLinguagemBase() << "\n";
                    lista << indie->getDev().getNome() << "\n";
                    lista << indie->getDev().getPaisOrigem() << "\n";

                    lista << indie->getNomeDesenvolvedor() << "\n";
                    lista << indie->getTemPublisher() << "\n";
                }else if (JogoMobile* mobile = dynamic_cast<JogoMobile*>(j)) {
                    lista << "MOBILE\n";
                    lista << mobile->getId() << "\n";
                    lista << mobile->getTitulo() << "\n";
                    lista << mobile->getPrecoBase() << "\n";
                    lista << mobile->getAnoLancamento() << "\n";
                    lista << mobile->getEng().getNome() << "\n";
                    lista << mobile->getEng().getLinguagemBase() << "\n";
                    lista << mobile->getDev().getNome() << "\n";
                    lista << mobile->getDev().getPaisOrigem() << "\n";
                    
                    lista << mobile->getPossuiAnuncios() << "\n";
                }
            }
            lista.close();
            std::cout << "Dados guardados com sucesso no lista 'dados.txt'.\n";
        }

        void carregarArquivo(){
            std::ifstream lista("dados.txt");

            if (!lista.is_open()) {
                return; 
            }

            std::string linha;

            if (std::getline(lista, linha)) {
                Jogo::ganhosTotais = std::stof(linha);
            }
            if (std::getline(lista, linha)) {
                Jogo::downloadsTotais = std::stof(linha);
            }

            while (std::getline(lista, linha)) {
                if (linha == "AAA" || linha == "INDIE" || linha == "MOBILE") {
                    std::string idStr, titulo, precoStr, anoStr;
                    std::string nomeEng, langEng, nomeDev, paisDev;

                    std::getline(lista, idStr);
                    std::getline(lista, titulo);
                    std::getline(lista, precoStr);
                    std::getline(lista, anoStr);
                    std::getline(lista, nomeEng);
                    std::getline(lista, langEng);
                    std::getline(lista, nomeDev);
                    std::getline(lista, paisDev);

                    int id = std::stoi(idStr);
                    float preco = std::stof(precoStr);
                    int ano = std::stoi(anoStr);

                    Engine eng(nomeEng, langEng);
                    Desenvolvedor dev(nomeDev, paisDev);

                    if (linha == "AAA") {
                        std::string orcamentoStr, qtdEstudiosStr;
                        std::getline(lista, orcamentoStr);
                        std::getline(lista, qtdEstudiosStr);
                        
                        catalogoJogos.push_back(new JogoAAA(id, titulo, preco, ano, eng, dev, 
                            std::stof(orcamentoStr), std::stoi(qtdEstudiosStr)));
                    } else if (linha == "INDIE") {
                        std::string nomeDevPrincipal, publisherStr;
                        std::getline(lista, nomeDevPrincipal);
                        std::getline(lista, publisherStr);
                        
                        catalogoJogos.push_back(new JogoIndie(id, titulo, preco, ano, eng, dev, 
                            nomeDevPrincipal, std::stoi(publisherStr)));
                    } else if (linha == "MOBILE") {
                        std::string anunciosStr;
                        std::getline(lista, anunciosStr);
                        
                        catalogoJogos.push_back(new JogoMobile(id, titulo, preco, ano, eng, dev, 
                            std::stoi(anunciosStr)));
                    }
                }
            }

            lista.close();
            std::cout << "Dados carregados com sucesso do ficheiro.\n";
        }
};