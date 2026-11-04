#include <iostream>
#include <string> 
#include <cstdlib>
#include <vector>
#include <fstream>
#include <limits>
#include <sstream>
#include <stdexcept>
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

        static std::string lerLinha(const std::string& prompt) {
            std::cout << prompt;
            std::string entrada;
            if (!std::getline(std::cin, entrada)) {
                throw std::runtime_error("Entrada encerrada.");
            }
            return entrada;
        }

        static bool converterInteiro(const std::string& entrada, int& valor, int minimo, int maximo) {
            std::istringstream stream(entrada);
            int valorLido;
            if (!(stream >> valorLido)) return false;
            if (valorLido < minimo || valorLido > maximo) return false;
            valor = valorLido;
            return true;
        }

        static bool converterFloat(const std::string& entrada, float& valor, float minimo) {
            std::istringstream stream(entrada);
            float valorLido;
            if (!(stream >> valorLido)) return false;
            if (valorLido < minimo) return false;
            valor = valorLido;
            return true;
        }

        static int lerInteiro(const std::string& prompt, int minimo, int maximo) {
            while (true) {
                int valor;
                if (converterInteiro(lerLinha(prompt), valor, minimo, maximo)) return valor;
                std::cout << "Entrada inválida. Digite um número entre " << minimo
                          << " e " << maximo << ".\n";
            }
        }

        static float lerFloat(const std::string& prompt, float minimo) {
            while (true) {
                float valor;
                if (converterFloat(lerLinha(prompt), valor, minimo)) return valor;
                std::cout << "Entrada inválida. Digite um número maior ou igual a "
                          << minimo << ".\n";
            }
        }

        static bool textoValido(const std::string& texto) {
            return texto.find_first_not_of(" \t\r\n") != std::string::npos;
        }

        static std::string lerTexto(const std::string& prompt) {
            while (true) {
                std::string entrada = lerLinha(prompt);
                if (textoValido(entrada)) return entrada;
                std::cout << "O texto não pode ficar vazio.\n";
            }
        }
    
    public:
        static int lerOpcao(const std::string& prompt, int minimo, int maximo) {
            return lerInteiro(prompt, minimo, maximo);
        }

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

            std::string nm = lerTexto("Nome do jogo: ");

            float preco = lerFloat("Preço base: ", 0.0f);

            int ano = lerInteiro("Ano de lançamento: ", 1950, 2026);

            std::cout << "\nEscolha a Engine:\n";
            std::cout << "1. Unreal Engine 5 (C++)\n";
            std::cout << "2. Unity (C#)\n";
            std::cout << "3. Godot (GDScript/C++)\n";
            std::cout << "4. Engine própria (Digitar)\n";
            int opEngine = lerInteiro("Opção: ", 1, 4);
            Engine eng("", "");
            if(opEngine == 1) {
                eng = Engine("Unreal Engine 5", "C++");
            }else if(opEngine == 2) {
                eng = Engine("Unity", "C#");
            }else if(opEngine == 3){
                eng = Engine("Godot", "GDScript");
            } else if (opEngine == 4) {
                std::string nomeEng = lerTexto("Nome da Engine: ");
                std::string langEng = lerTexto("Linguagem base: ");
                eng = Engine(nomeEng, langEng);
            }

            std::cout << "\n--- Dados da Desenvolvedora ---\n";
            std::string nomeDev = lerTexto("Nome da desenvolvedora: ");
            std::string paisDev = lerTexto("País de origem: ");

            Desenvolvedor dev(nomeDev, paisDev);

            int tipoJogo = lerInteiro("\nTipo (1 - AAA | 2 - Indie | 3 - Mobile): ", 1, 3);

            if(tipoJogo == 1) {
                float marketing = lerFloat("Orçamento do marketing: R$ ", 0.0f);
                int qtdE = lerInteiro("Quantidade de estúdios envolvidos: ", 1,
                                      std::numeric_limits<int>::max());
            
                catalogoJogos.push_back(new JogoAAA(
                    id, nm, preco, ano, eng, dev, marketing, qtdE
                ));
            }else if(tipoJogo == 2){
                std::string devPrincipal = lerTexto("Nome do desenvolvedor principal: ");
                bool publisher = lerInteiro("Possui publisher? (1 - Sim / 0 - Não): ", 0, 1) == 1;

                catalogoJogos.push_back(new JogoIndie(
                    id, nm, preco, ano, eng, dev, devPrincipal, publisher
                ));
            } else {
                bool anuncios = lerInteiro("Possui anúncios? (1 - Sim / 0 - Não): ", 0, 1) == 1;

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
            if (titulo.find_first_not_of(" \t\r\n") == std::string::npos) return -1;

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
            for (size_t i = 0; i < indicesEncontrados.size(); i++) {
                std::cout << "[" << i + 1 << "] "
                          << catalogoJogos[indicesEncontrados[i]]->getTitulo() << "\n";
            }
            
            int escolha = lerInteiro("Digite o índice desejado: ", 1,
                                     static_cast<int>(indicesEncontrados.size()));
            return indicesEncontrados[escolha - 1];
        }

        void exibirUmJogo() {
            system("cls");
            std::cout << traco << std::endl;
            std::cout << "Exibir Detalhes do Jogo" << std::endl;
            std::string nomeP = lerTexto("Digite o nome do jogo: ");

            int idJogo = pesquisar(nomeP);
            if (idJogo != -1) {
                std::cout << traco << std::endl;
                catalogoJogos[idJogo]->exibirInfo();
                std::cout << traco << std::endl;
            } else {
                std::cout << "Nenhum jogo encontrado com esse nome.\n";
            }
            system("pause");
        }

        void alterarJogo(){
            std::cout << traco << std::endl;
            std::cout << "Editar Jogo" << std::endl;
            std::cout << traco << std::endl;

            std::string nomeP = lerTexto("Digite o nome do jogo que deseja editar: ");

            int idJogo;
            idJogo = pesquisar(nomeP);
            if (idJogo == -1) {
                std::cout << "Nenhum jogo encontrado com esse nome.\n";
                system("pause");
                return; 
            }

            std::cout << traco << std::endl;
            std::cout << "Editando o seguinte jogo:" << std::endl;
            catalogoJogos[idJogo]->exibirInfo();
            std::cout << traco << std::endl;

            std::string entrada;

            std::cout << "Nome do jogo [" << catalogoJogos[idJogo]->getTitulo() << "]: ";
            if (!std::getline(std::cin, entrada)) throw std::runtime_error("Entrada encerrada.");
            if (!entrada.empty()) {
                while (!textoValido(entrada)) {
                    std::cout << "O texto não pode ficar vazio.\n";
                    if (!std::getline(std::cin, entrada)) throw std::runtime_error("Entrada encerrada.");
                }
                catalogoJogos[idJogo]->setTitulo(entrada);
            }

            std::cout << "Preço Base [" << catalogoJogos[idJogo]->getPrecoBase() << "]: ";
            if (!std::getline(std::cin, entrada)) throw std::runtime_error("Entrada encerrada.");
            if (!entrada.empty()) {
                float preco;
                while (!converterFloat(entrada, preco, 0.0f)) {
                    std::cout << "Preço inválido. Digite um valor maior ou igual a 0: ";
                    if (!std::getline(std::cin, entrada)) throw std::runtime_error("Entrada encerrada.");
                }
                catalogoJogos[idJogo]->setPrecoBase(preco);
            }

            std::cout << "Ano de Lançamento [" << catalogoJogos[idJogo]->getAnoLancamento() << "]: ";
            if (!std::getline(std::cin, entrada)) throw std::runtime_error("Entrada encerrada.");
            if (!entrada.empty()) {
                int ano;
                while (!converterInteiro(entrada, ano, 1950, 2026)) {
                    std::cout << "Ano inválido. Digite um ano entre 1950 e 2026: ";
                    if (!std::getline(std::cin, entrada)) throw std::runtime_error("Entrada encerrada.");
                }
                catalogoJogos[idJogo]->setAnoLancamento(ano);
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

            std::string nomeP = lerTexto("Digite o nome do jogo que deseja deletar: ");

            int idJogo;
            idJogo = pesquisar(nomeP);
            if (idJogo == -1) {
                std::cout << "Nenhum jogo encontrado com esse nome.\n";
                system("pause");
                return; 
            }

            std::cout << traco << std::endl;
            std::cout << "Jogo selecionado para remoção: " << std::endl;
            catalogoJogos[idJogo]->exibirInfo();
            std::cout << traco << std::endl;

            int confirmacao = lerInteiro(
                "Tem a certeza absoluta que deseja remover este jogo? (1 - Sim / 0 - Nao): ", 0, 1);
            
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

            std::string nomeP = lerTexto("Digite o nome do jogo que deseja vender: ");

            int indexVetor = pesquisar(nomeP);
            
            if (indexVetor == -1) {
                std::cout << "Nenhum jogo encontrado com esse nome.\n";
                system("pause");
                return; 
            }

            Jogo* jogoVendido = catalogoJogos[indexVetor];
            int quantidadeMaxima = std::numeric_limits<int>::max() - jogoVendido->getCopiasVendidas();
            if (quantidadeMaxima < 1) {
                std::cout << "Este jogo atingiu o limite de cópias vendidas.\n";
                return;
            }

            int qtd = lerInteiro("\nQuantidade da venda: ", 1, quantidadeMaxima);
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
                float ganhos;
                if (converterFloat(linha, ganhos, 0.0f)) {
                    Jogo::ganhosTotais = ganhos;
                } else {
                    std::cout << "Faturamento inválido no arquivo; usando zero.\n";
                }
            }
            if (std::getline(lista, linha)) {
                int downloads;
                if (converterInteiro(linha, downloads, 0, std::numeric_limits<int>::max())) {
                    Jogo::downloadsTotais = downloads;
                } else {
                    std::cout << "Total de downloads inválido no arquivo; usando zero.\n";
                }
            }

            while (std::getline(lista, linha)) {
                if (linha.empty()) continue;
                if (linha != "AAA" && linha != "INDIE" && linha != "MOBILE") {
                    std::cout << "Tipo de jogo inválido no arquivo; linha ignorada.\n";
                    continue;
                }

                std::string idStr, titulo, precoStr, anoStr;
                std::string nomeEng, langEng, nomeDev, paisDev;
                if (!std::getline(lista, idStr) || !std::getline(lista, titulo) ||
                    !std::getline(lista, precoStr) || !std::getline(lista, anoStr) ||
                    !std::getline(lista, nomeEng) || !std::getline(lista, langEng) ||
                    !std::getline(lista, nomeDev) || !std::getline(lista, paisDev)) {
                    std::cout << "Registro incompleto no arquivo; carregamento interrompido.\n";
                    break;
                }

                std::string dadoEspecifico1, dadoEspecifico2;
                if (linha == "AAA") {
                    if (!std::getline(lista, dadoEspecifico1) ||
                        !std::getline(lista, dadoEspecifico2)) {
                        std::cout << "Registro incompleto no arquivo; carregamento interrompido.\n";
                        break;
                    }
                } else if (linha == "INDIE") {
                    if (!std::getline(lista, dadoEspecifico1) ||
                        !std::getline(lista, dadoEspecifico2)) {
                        std::cout << "Registro incompleto no arquivo; carregamento interrompido.\n";
                        break;
                    }
                } else if (!std::getline(lista, dadoEspecifico1)) {
                    std::cout << "Registro incompleto no arquivo; carregamento interrompido.\n";
                    break;
                }

                int id, ano;
                float preco;
                bool valido = converterInteiro(idStr, id, 0, std::numeric_limits<int>::max()) &&
                    converterFloat(precoStr, preco, 0.0f) &&
                    converterInteiro(anoStr, ano, 1950, 2026) &&
                    textoValido(titulo) && textoValido(nomeEng) && textoValido(langEng) &&
                    textoValido(nomeDev) && textoValido(paisDev);

                Engine eng(nomeEng, langEng);
                Desenvolvedor dev(nomeDev, paisDev);
                if (linha == "AAA") {
                    float marketing;
                    int qtdEstudios;
                    valido = valido &&
                        converterFloat(dadoEspecifico1, marketing, 0.0f) &&
                        converterInteiro(dadoEspecifico2, qtdEstudios, 1,
                                         std::numeric_limits<int>::max());
                    if (valido) {
                        catalogoJogos.push_back(new JogoAAA(
                            id, titulo, preco, ano, eng, dev, marketing, qtdEstudios));
                    }
                } else if (linha == "INDIE") {
                    int publisher;
                    valido = valido && textoValido(dadoEspecifico1) &&
                        converterInteiro(dadoEspecifico2, publisher, 0, 1);
                    if (valido) {
                        catalogoJogos.push_back(new JogoIndie(
                            id, titulo, preco, ano, eng, dev, dadoEspecifico1, publisher == 1));
                    }
                } else {
                    int anuncios;
                    valido = valido && converterInteiro(dadoEspecifico1, anuncios, 0, 1);
                    if (valido) {
                        catalogoJogos.push_back(new JogoMobile(
                            id, titulo, preco, ano, eng, dev, anuncios == 1));
                    }
                }

                if (!valido) {
                    std::cout << "Registro inválido no arquivo; jogo ignorado.\n";
                }
            }

            lista.close();
            std::cout << "Dados carregados com sucesso do ficheiro.\n";
        }
};